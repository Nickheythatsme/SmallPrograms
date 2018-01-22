#include "planet.h"
/* Nicholas Grout
 * Program 1
 */

//This function returns the distance from the planet to the sun
int planet::return_distance(void) const
{
    return distance;
}

//This function displays the planet info
void planet::display(void) const
{
    //Call base class's display first, then do our own!.
    celestial_body::display();

    //Display the distance to the sun
    celestial_body::display("Distance to sun", distance);

    //Display each moon's information
    celestial_body::display("Moons",num_moons);
    return;
}

//Display moons with this function:
void planet::display_moons(void) const
{
    for(int i = 0; i < num_moons; ++i)
        moons[i] -> display();
    return;
}

//This function sets the distance randomly, depeding on what max
//and min are.
unsigned int planet::random_value(unsigned int min, unsigned int max) const
{
    //Help make random more random by giving it the current clock time.
    srand( clock() );

    //We assign a random value (lower than max) to temp
    unsigned int temp = rand() % max;

    //We make sure the rand value is higher than the min here:
    while( temp < min )
        temp = rand() % max;

    return temp;
}

float planet::random_float(float min, float max) const
{
    //Help make random more random by giving it the current clock time.
    srand( clock() );
    unsigned int top = rand() % 10000;
    float value = top / 10000.0;
    value = max * value;

    while( value < min )
    {
        top = rand() % 10000;
        value = top / 10000.0;
        value = max * value;
    }
    return value;
}

bool planet::make_moon_name(int i, char *& moon_name) const
{
    moon_name = new char[strlen("moon  \0") + 1];
    strcpy(moon_name, "moon  \0");
    moon_name[5] = i + 48;
    return true;
}

planet::planet(const char * name, int min_distance, int max_distance, int max_moons) :
    celestial_body(name, random_float(10.0,10000.0))
{
    //Calling function to set the distance randomly.
    distance = random_value(min_distance, max_distance);

    //Making the planet's moons randomly here:
    num_moons = random_value(0,max_moons);
    if( !num_moons ) moons = NULL;
    else
    {
        char * moon_name = NULL;
        moons = new moon * [num_moons];
        for(int i = 0; i < num_moons; ++i)
        {
            make_moon_name(i, moon_name);
            moons[i] = new moon(moon_name, random_float(1.0,100.0), random_value(100,100000));
            delete [] moon_name;
        }
    }
}

planet::planet(const planet & obj) : celestial_body(obj)
{
    distance = obj.distance;
    num_moons = obj.num_moons;
    if( !num_moons ) moons = NULL;
    else
    {
        moons = new moon * [num_moons];
        for(int i = 0; i < num_moons; ++i)
            moons[i] = new moon(*obj.moons[i]);
    }
}

planet::~planet()
{
    for(int i = 0; i < num_moons; ++i)
    {
        delete moons[i];
        moons[i] = NULL;
    }
    delete [] moons;
    moons = NULL;
}


#undef MAX_DISTANCE
#undef MIN_DISTANCE
