#include "../node.h"
/* Nicholas Grout
 * Program 1
 */

#ifndef INNER_PLANET_
#define INNER_PLANET_

class inner_planet : public node
{
    public:
        inner_planet(char * name);
        inner_planet(const inner_planet & obj);
        ~inner_planet();
        void display(void) const;
    private:
        bool has_atmosphere;
        //Rating between 0.0% and 100.0%, indicating the livibility of the planet
        float livability;
};

#endif
