#include "../node.h"
/* Nicholas Grout
 * Program 1
 */


#ifndef OUTER_PLANET_
#define OUTER_PLANET_

class outer_planet : public node
{
    public:
        outer_planet(char * name);
        outer_planet(const outer_planet & obj);
        ~outer_planet(void);
        void display(void) const;
    private:
        bool is_gas;
        bool has_rings;
};
#endif
