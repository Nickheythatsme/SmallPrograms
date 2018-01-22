#include "solar_system.h"
/* Nicholas Grout
 * Program 1
 */

//This function displays all of the nodes in the DLL
bool solar_system::display_all(void) const
{
    if(!head) return false;

    cout << "\nSolar system: " << name << endl;
    node * current = head;
    while( current )
    {
        display( current );
        current = current -> next_node();
    }
    return true;
}

//This function calls the right display function, depending on what type of
//object is stored in the DLL
bool solar_system::display(const celestial_body * obj) const
{
    obj -> display();
    return true;
}

//This function inserts a new inner planet into the DLL. There's one for inner
//and outer planets.
bool solar_system::insert(const inner_planet * new_planet)
{
    if( !new_planet ) return false;
    if( !head )
    {
        head = new inner_planet(*new_planet);
        return true;
    }

    //This is in case head is less than the new node.
    if( head -> return_distance() < new_planet -> return_distance() )
    {
        node * new_head = new inner_planet( *new_planet );
        node * temp_head = head;

        head = new_head;
        new_head -> insert_next( temp_head );
        return true;
    }

    //Calling the recursive function here:
    return insert(new_planet, head);
}

//Same function but for outer planets.
bool solar_system::insert(const outer_planet * new_planet)
{
    if( !new_planet ) return false;
    if( !head )
    {
        head = new outer_planet(*new_planet);
        return true;
    }

    //This is in case head is less than the new node.
    if( head -> return_distance() < new_planet -> return_distance() )
    {
        node * new_head = new outer_planet( *new_planet );
        node * temp_head = head;

        head = new_head;
        new_head -> insert_next( temp_head );
        return true;
    }

    //Calling the recursive function here:
    return insert(new_planet, head);
}

//Insert a new planet in a DLL in decending order with this function.
//
//The node handles the actual insertion while the solar systems class handles
//the knowing where to place the new node.
bool solar_system::insert(const inner_planet * new_planet, node * head)
{
    if( !head ) return false;

    //In case we're at the end of the DLL, we should insert the new node.
    if( !head -> next_node() )
    {
        node * new_planet_copy = new inner_planet( *new_planet );
        head -> insert_next( new_planet_copy );
        return true;
    }
    //In case the next node is less than this new node, we should insert the new
    //node between the current node and the next.
    if( new_planet -> return_distance() > head -> next_node() -> return_distance() )
    {
        node * new_planet_copy = new inner_planet( *new_planet );
        head -> insert_next( new_planet_copy );
        return true;
    }

    return insert(new_planet, head -> next_node() );
}

//Same function but for outer planets.
bool solar_system::insert(const outer_planet * new_planet, node * head)
{
    if( !head ) return false;

    //In case we're at the end of the DLL, we should insert the new node.
    if( !head -> next_node() )
    {
        node * new_planet_copy = new outer_planet( *new_planet );
        head -> insert_next( new_planet_copy );
        return true;
    }
    //In case the next node is less than this new node, we should insert the new
    //node between the current node and the next.
    if( new_planet -> return_distance() > head -> next_node() -> return_distance() )
    {
        node * new_planet_copy = new outer_planet( *new_planet );
        head -> insert_next( new_planet_copy );
        return true;
    }

    return insert(new_planet, head -> next_node() );
}

//Standard constructor for the solar system
solar_system::solar_system(const char * new_name) : 
    the_sun(new_name)
{
    head = NULL;
    name = new char[strlen(new_name) + 1];
    strcpy(name, new_name);
}

//This is the copy constructor for the solar system. It does not allocate new
//planets completely, it will reduce all inner/outer planets to nodes :(
solar_system::solar_system(const solar_system & obj) : 
    the_sun(obj.the_sun)
{
    if( obj.head )
        head = new node(*obj.head);
    if( obj.name )
    {
        name = new char[strlen(obj.name) + 1];
        strcpy(name, obj.name);
    }
}

//This is the default destructor for the solar system
solar_system::~solar_system()
{
    if( name ) delete [] name;
    name = NULL;
    if( head )
        delete head;
    head = NULL;
}
