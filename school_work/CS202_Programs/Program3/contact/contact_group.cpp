/*
 * Nicholas Grout
 * Program 3
 */
#include "contact_group.h"

#define TEMP 100

//Reading in from a file here:
ifstream& contact_group::read_in(ifstream & in, text & text_obj)
{
    char temp[TEMP];
    in.get(temp,TEMP,',');
    text_obj = temp;
    in.ignore(TEMP,',');
    return in;
}

//Read in until a specified delimeter, then keep reading in if you haven't 
//reached it yet.
ifstream& contact_group::read_in(ifstream & in, text & text_obj, char delim)
{
    char temp[TEMP];
    char temp_char = ' ';
    int i = 0;

    //Get Keywords
    while( temp_char != delim )
    {
        i = 0;
        temp[i] = '\0';
        in >> temp_char;
        while(temp_char != ',' && temp_char != delim)
        {
            temp[i] = temp_char;
            in.get(temp_char);
            ++i;
        }
        temp[i] = '\0';
        text_obj << temp;
    }
    return in;
}

//Output to a stream here!
ostream& operator<<(ostream & out, const contact_group & obj)
{
    obj.display(out);
    return out;
}

//Use this function to call the display function on derived classes like the
//event class. It doesn't do anything but kick start the node's display all
ostream& contact_group::display(ostream & out) const
{
    if( head )
        head -> display_all(out);
    return out;
}

contact_group& operator<<(contact_group & obj, const contact & new_contact)
{
    if(!obj.head)
    {
        obj.head = new contact_node(new_contact);
        return obj;
    }

    *obj.head << new_contact;
    return obj;
}

//This is the extraction operator. It takes one node out of the DLL.
contact& operator>>(contact_group & obj,
        contact & new_contact)
{
    obj.remove_head(new_contact);
    return new_contact;
}

//This removes one node from the front of the DLL.
bool contact_group::remove_head(contact & to_return)
{
    if(!head) return false;
    to_return = *head;
    contact_node * temp = head;
    delete head;
    head = temp -> next_node();
    return true;
}

contact_group& contact_group::operator = (const contact_group & obj)
{
    if( this == &obj ) return *this;
    remove_all(head);
    head = NULL;
    if( obj.head )
        head = new contact_node(*obj.head);
    return *this;
}

//This finds a matching contact and returns it. This allows the client to
//change who is attending/any infor they need to change as well.
contact& contact_group::operator[](const char * text) const
{
    contact * ptr = find(text, head);
    if(!ptr) return *head;
    return *ptr;
}

contact* contact_group::find(const char * name, contact_node * head) const
{
    if(!head) return NULL;
    if( *head == name )
        return head;
    return find(name, head -> next_node() );
}

contact_group::contact_group()
{
    head = NULL;
}

//COPY CONSTRUCTOR. It also copies the nodes in the other group.
contact_group::contact_group(const contact_group & obj)
{
    if( obj.head )
        head = new contact_node(*obj.head);
    else
        head = NULL;
}

//DESTRUCTOR
contact_group::~contact_group()
{
    remove_all(head);
    head = NULL;
}

//removes all nodes in the DLL
void contact_group::remove_all(contact_node * head)
{
    if(!head) return;
    remove_all(head -> next_node() );
    delete head;
    return;
}

#undef TEMP
