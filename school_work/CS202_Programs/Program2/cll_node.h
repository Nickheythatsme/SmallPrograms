#include "solar_system_files/solar_system.h"


#ifndef CLL_NODE_
#define CLL_NODE_

class cll_node
{
    public:
        node(const inner_planet * new_planet);
        node(const outer_planet * new_planet);
        node(const node & obj);
        ~node();
    private:
        planet * data;
        cll_node * next;
        bool is_inner;
};

#endif
