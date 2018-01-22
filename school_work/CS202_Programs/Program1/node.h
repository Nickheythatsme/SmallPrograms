#include "celestial_bodies/planet.h"
/* Nicholas Grout
 * Program 1
 */

#ifndef NODE_
#define NODE_

class node : public planet
{
    public:
        node(const char * name, int min_distance, int max_distance, int max_moons);
        node(const node & obj);
        ~node();
        bool insert_next(node * temp_new_node);
        node* next_node(void);
        node* prev_node(void);
    private:
        bool connect_prev( node * new_previous );
        bool connect_next( node * new_next );
        node * next;
        node * prev;
};

#endif
