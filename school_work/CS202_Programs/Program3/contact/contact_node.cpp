/*
 * Nicholas Grout
 * Program 3
 */
#include "contact_group.h"

//Insert a new contact into this contact DLL with the insertion operator.
contact_node& operator<<(contact_node & obj, const contact_node & new_contact)
{
    obj.insert(new_contact);
    return obj;
}

contact_node& operator<<(contact_node & obj, const contact & new_contact)
{
    contact_node new_node(new_contact);
    new_node.next = NULL;
    obj.insert(new_node);
    return obj;
}

bool contact_node::insert(const contact_node & obj)
{
    if(!next)
    {
        next = new contact_node(obj);
        return true;
    }
    return insert(obj,next);
}

bool contact_node::insert(const contact_node & obj,contact_node *& root)
{
    if( !root ) 
        return insert(obj, root -> next );
    root = new contact_node(obj);
    return true;
}

//This connects a new node onto the next pointer. It acts as a wrapper for the
//real function, connet_next(connect_node*).
bool contact_node::insert_next(const contact_node & obj)
{
    contact_node * new_contact = new contact_node(obj);
    return connect_next( new_contact );
}

//This is for traversal. It returns the next node.
contact_node* contact_node::next_node(void) const
{
    return next;
}


//This displays the data for this class.
ostream& contact_node::display(ostream & out) const
{
    contact::display(out);
    return out;
}

//This displays all nodes in the DLL
bool contact_node::display_all(ostream & out) const
{
    display(out);
    if( next )
    {
        out << '\n';
        next -> display_all(out);
    }
    return true;
}

//This is the friend function so we can use ostream with this class.
ostream& operator<<(ostream & out, const contact_node & obj)
{
    obj.display(out);
    return out;
}

contact_node& contact_node::operator=(const contact_node & obj)
{
    if( this == &obj ) return *this;
    next = obj.next;
    return *this;
}

//Connect a new node to the next pointer. If there is already a node there,
//we shift that node down and put the new node in.
bool contact_node::connect_next(contact_node * new_node)
{
    if( !next )
    {
        next = new_node;
        return true;
    }
    contact_node * temp = next;
    next = new_node;
    new_node -> next = temp;
    return true;
}

//This is the CONSTRUCTOR.
contact_node::contact_node(const char * name, const char * phone_num) : 
    contact(name, phone_num)
{
    next = NULL;
}

//This is the default CONSTRUCTOR.
contact_node::contact_node() : contact()
{
    next = NULL;
}

//This is the COPY CONSTRUCTOR. It performs a deep copy on the contact data,
//but does NOT copy the next nodes connected to obj.
contact_node::contact_node(const contact_node & obj) : contact(obj)
{
    next = NULL;
    if( obj.next )
        next = new contact_node(*obj.next);
}

//Constructor for a contact
contact_node::contact_node(const contact & obj) : contact(obj)
{
    next = NULL;
}

//This is the DESTRUCTOR. There is no dynamic mem in contact_node so we don't
//need to worry about deleting it. Next should be deleted by client.
contact_node::~contact_node()
{
}
