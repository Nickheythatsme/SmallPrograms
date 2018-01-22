#include "celestial_bodies/inner_planet.h"
#include "celestial_bodies/outer_planet.h"
/* Nicholas Grout
 * Program 1
 */


#ifndef SOLAR_SYSTEM_
#define SOLAR_SYSTEM_

class solar_system
{
    public:
        solar_system(const char * name);
        solar_system(const solar_system & obj);
        ~solar_system();
        bool display_all(void) const;
        bool insert(const inner_planet * new_planet);
        bool insert(const outer_planet * new_planet);
    protected:
        bool display(const celestial_body * obj) const;
    private:
        bool insert(const inner_planet * new_planet, node * head);
        bool insert(const outer_planet * new_planet, node * head);
        char * name;
        node * head;
        celestial_body sun;
};

#endif
