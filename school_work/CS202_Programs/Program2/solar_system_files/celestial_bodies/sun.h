#include "celestial_body.h"


#ifndef SUN_
#define SUN_

class sun: public celestial_body
{
    public:
        sun(const char * name);
        sun(const sun & obj);
        ~sun();
        virtual void display(void) const;
    private:
        //this class happens to have no private data.
};

#endif
