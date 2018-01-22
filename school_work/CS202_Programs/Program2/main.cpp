#include "galaxy.h"
#include <fstream>

#define TEMP 1000
#define DELIM ','

/* Nicholas Grout
 * Program 1
 */

int load_planets(const char * file_in, galaxy & obj, int system);

int main(int argc, char * argv[])
{
    //solar_system test_system("TEST SYSTEM");
    char ** system_names = new char* [2];

    system_names[0] = new char[strlen("System Number 1") + 1];
    strcpy( system_names[0], "System Number 1" );

    system_names[1] = new char[strlen("System Number 2") + 1];
    strcpy( system_names[1], "System Number 2" );

    galaxy test_galaxy( system_names, 2 );
    

    //Loading the first solar system
    int num_planets = load_planets("solar_system1.txt", test_galaxy, 0);
    if( num_planets == 0 ) return 1;
    else 
        cout << "Planets loaded from " << "solar_system1.txt" << ": " 
             << num_planets << endl;

    //Loading the second solar system
    num_planets = load_planets("solar_system2.txt", test_galaxy, 1);
    if( num_planets == 0 ) return 1;
    else 
        cout << "Planets loaded from " << "solar_system2.txt" << ": " 
             << num_planets << endl;
    
    test_galaxy.display_all();
    

    delete [] system_names[0];
    delete [] system_names[1];
    system_names[0] = system_names[1] = NULL;
    delete [] system_names;
    system_names = NULL;

    return 0;
}

int load_planets(const char * file_in, galaxy & obj, int system)
{
    if( !file_in ) return 0;

    ifstream fin;
    inner_planet * temp_planet_inner = NULL;
    outer_planet * temp_planet_outer = NULL;
    char temp_planet_name[TEMP];
    char temp_planet_type[3];
    int current_planet = 0;

    fin.open(file_in);

    fin.get(temp_planet_name,TEMP,DELIM);
    fin.ignore(TEMP,DELIM);

    while( !fin.eof() )
    {
        fin.get(temp_planet_type,TEMP,'\n');
        fin.ignore(TEMP,'\n');

        if( temp_planet_type[0] == '1' )
        {
            temp_planet_outer = new outer_planet( temp_planet_name );
            obj.insert(temp_planet_outer,system);
        }

        else 
        {
            temp_planet_inner = new inner_planet( temp_planet_name );
            obj.insert(temp_planet_inner,system);
        }

        if( temp_planet_outer )
        {
            delete temp_planet_outer;
            temp_planet_outer = NULL;
        }

        if( temp_planet_inner )
        {
            delete temp_planet_inner;
            temp_planet_inner = NULL;
        }
        ++current_planet;

        fin.get(temp_planet_name,TEMP,DELIM);
        fin.ignore(TEMP,DELIM);
    }

    fin.close();
    return current_planet;
}
