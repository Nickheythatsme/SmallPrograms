#include "sun.h"

void sun::display(void) const
{ 
    //Call base class's display function.
    celestial_body::display();
    return;
}

sun::sun(const char * name) : celestial_body(name, 100000000)
{ }

sun::sun(const sun & obj) : celestial_body(obj)
{ }

sun::~sun()
{ }
