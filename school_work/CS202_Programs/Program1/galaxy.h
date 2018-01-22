#include "solar_system.h"
/* Nicholas Grout
 * Program 1
 */


#ifndef GALAXY_
#define GALAXY_

class galaxy
{
    public:
        galaxy(char ** names, int count);
        galaxy(const galaxy & obj);
        ~galaxy();
        bool insert(const inner_planet * new_planet, int system_num);
        bool insert(const outer_planet * new_planet, int system_num);
        bool display_all(void);
        int next_planet();
        int next_system();
    private:
        solar_system ** systems;
        planet * current_planet;
        int current_solar_system;
        int solar_system_count;
};

#endif
