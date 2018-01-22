#include "moon.h"
/* Nicholas Grout
 * Program 1
 */

void moon::display(void) const
{
    cout << endl;
    celestial_body::display();
    celestial_body::display("Distance to planet",distance_to_planet,"miles");
    celestial_body::display("Revolution time",revolution,"days");
    return;
}

bool moon::make_moon_name(int i, char *& moon_name)
{
    moon_name = new char[strlen("moon  \0") + 1];
    strcpy(moon_name, "moon  \0");
    moon_name[5] = i + 48;
    return true;
}

moon::moon(const char * name, float new_revolution, int distance) : 
    celestial_body(name, 10)
{

    revolution = new_revolution;
    distance_to_planet = distance;
}

moon::moon(const moon & obj) : celestial_body(obj)
{
    revolution = obj.revolution;
    distance_to_planet = obj.distance_to_planet;
}

moon::~moon()
{
}
