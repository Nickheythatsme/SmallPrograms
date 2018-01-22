#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
/* Nicholas Grout
 * Program 1
 */

//Base class for all astronomical bodies. Sun, moon, planets will all be 
//derived from this in some way.
#ifndef CELESTIAL_BODY_
#define CELESTIAL_BODY_
const int BUFFER = 20;

class celestial_body
{
    public:
        virtual ~celestial_body();
        virtual void display(void) const;
        virtual int return_distance(void) const;
    protected:
        celestial_body(const char * name, float diameter);
        celestial_body(const celestial_body & obj);
        void display(const char * var, int value, const char * unit = NULL) const;
        void display(const char * var, float value, const char * unit = NULL) const;
        void display(const char * var, char * value, const char * unit = NULL) const;
    private:
        void set_cout() const;
        float diameter;
        char * name;
};

#endif
