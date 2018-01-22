#include "celestial_body.h"
#include "moon.h"
/* Nicholas Grout
 * Program 1
 */

#ifndef PLANET_
#define PLANET_

class planet : public celestial_body
{
    public:
        planet(const char * name, int min_distance, int max_distance, int max_moons);
        planet(const planet & obj);
        virtual ~planet();
        virtual void display(void) const;
        void display_moons(void) const;
        virtual int return_distance(void) const;
    protected:
        unsigned int random_value(unsigned int min, unsigned int max);
        float random_float(float min, float max);
    private:
        bool make_moon_name(int i, char *& moon_name);
        int distance;
        int num_moons;
        moon ** moons;
};

#endif
