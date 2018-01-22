#include "galaxy.h"
/* Nicholas Grout
 * Program 1
 */


bool galaxy::display_all(void)
{
    cout << endl << "Displaying all in Galaxy" << endl;
    for(int i = 0; i < solar_system_count; ++i)
    {
        systems[i] -> display_all();
        cout << endl << endl;
    }
    return true;
}

bool galaxy::insert(const inner_planet * new_planet, int system_num)
{
    if( system_num > solar_system_count ) return false;
    return systems[system_num] -> insert(new_planet);
}

bool galaxy::insert(const outer_planet * new_planet, int system_num)
{
    if( system_num > solar_system_count ) return false;
    return systems[system_num] -> insert(new_planet);
}

galaxy::galaxy(char ** names, int number_of_systems)
{
    systems = new solar_system* [number_of_systems];

    for(int i = 0; i < number_of_systems; ++i)
        systems[i] = new solar_system(names[i]);

    solar_system_count = number_of_systems;

    current_solar_system = 0;
    current_planet = NULL;
}

galaxy::galaxy(const galaxy & obj)
{
    solar_system_count = obj.solar_system_count;

    systems = new solar_system* [obj.solar_system_count];
    for( int i = 0; i < solar_system_count; ++i)
        systems[i] = new solar_system( *obj.systems[i] );

    current_solar_system = obj.current_solar_system;
    current_planet = NULL;

}

galaxy::~galaxy()
{
    for(int i = 0; i < solar_system_count; ++i)
    {
        delete systems[i];
        systems[i] = NULL;
    }
    delete [] systems;
    systems = NULL;

    if( current_planet )
        current_planet = NULL;
}

