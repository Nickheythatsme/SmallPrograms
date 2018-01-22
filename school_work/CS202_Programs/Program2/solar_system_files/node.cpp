#include "node.h"
/* Nicholas Grout
 * Program 1
 */

node::node(const char * name, int min_distance, int max_distance, int max_moons) : 
    planet(name, min_distance, max_distance, max_moons)
{
    next = prev = NULL;
}

node::node(const node & obj) : planet(obj)
{
    next = obj.next;
    prev = obj.prev;
}

node::~node()
{
    if( next ) delete next;
    next = prev = NULL;
}

bool node::insert_next(node * new_node)
{
    if( !next )
    {
        next = new_node;
        next -> connect_prev( this );
    }
    else
    {
        node * temp_next = next;
        next = new_node;

        temp_next -> connect_prev( this );
        new_node -> connect_prev( this );
        new_node -> connect_next( temp_next );
    }
    return true;
}

bool node::connect_prev( node * new_previous )
{
    prev = new_previous;
    return true;
}

bool node::connect_next( node * new_next )
{
    next = new_next;
    return true;
}

node* node::next_node(void)
{
    return next;
}

node* node::prev_node(void)
{
    return prev;
}
