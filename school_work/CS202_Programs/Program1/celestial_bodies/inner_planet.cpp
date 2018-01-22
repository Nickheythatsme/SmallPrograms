#include "inner_planet.h"
/* Nicholas Grout
 * Program 1
 */

void inner_planet::display(void) const
{
    planet::display();
    planet::celestial_body::display("Has atmosphere",has_atmosphere);
    planet::celestial_body::display("Livability",livability,"%");
}


inner_planet::inner_planet(char * name) : node(name, 10, 4999, 2)
{
    has_atmosphere = planet::random_value(0,100) % 2;
    livability = planet::random_float(0.0, 100.0);
}

inner_planet::inner_planet(const inner_planet & obj) : node(obj)
{
    has_atmosphere = obj.has_atmosphere;
    livability = obj.livability;
}

inner_planet::~inner_planet()
{
}
