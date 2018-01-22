#include "outer_planet.h"
/* Nicholas Grout
 * Program 1
 */

void outer_planet::display(void) const
{
    planet::display();
    planet::celestial_body::display("Has rings",has_rings);
    planet::celestial_body::display("Is gas",is_gas);
    return;
}

outer_planet::outer_planet(char * name) : node(name, 5000, 10000, 30)
{
    is_gas = planet::random_value(0,100) % 2;
    has_rings  = planet::random_value(0,100) % 2;
}

outer_planet::outer_planet(const outer_planet & obj) : node(obj)
{
    is_gas = obj.is_gas;
    has_rings =  obj.has_rings;
}

outer_planet::~outer_planet()
{
}
