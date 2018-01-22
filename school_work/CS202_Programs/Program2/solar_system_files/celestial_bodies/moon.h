#include "celestial_body.h"
/* Nicholas Grout
 * Program 1
 */


#ifndef MOON_
#define MOON_
class moon : public celestial_body
{
    public:
        //The moon's name is variable, but the size of the moon is not. The
        //distance from the moon to the planet is also variable.
        moon(const char * name, 
                float revolution, int distance_to_planet);
        moon(const moon & obj);
        virtual ~moon();
        void display(void) const;
    private:
        //This is the time it takes to revolve around the planet
        bool make_moon_name(int i, char *& moon_name);
        int revolution;
        int distance_to_planet;
};
#endif
