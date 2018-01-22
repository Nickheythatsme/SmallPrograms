/*
 * Nicholas Grout
 * Program 3
 */
#include "enode.h"

enode& enode::operator=(const enode & obj)
{
    this -> event::operator=( obj );

    if( next )
    {
        delete next;
        next = NULL;
    }

    if( obj.next )
        next = new enode(*obj.next);

    keyvalue = obj.keyvalue;
    return *this;
}

bool enode::set_key(const char * key)
{
    keyvalue = key;
    return true;
}

bool enode::set_event(const event & obj)
{
    this -> event::operator=(obj);
    return true;
}

enode& operator<<(enode & obj, const enode & new_node)
{
    if(!obj.next)
    {
        obj.next = new enode(new_node);
        return obj;
    }
    *obj.next << new_node;
    return obj;
}


ostream& operator<<(ostream & out, const enode & obj)
{
    obj.display(out);
    return out;
}

ostream& enode::display(ostream & out) const
{
    event::display(out);
    if( next )
    {
        out << endl << endl;
        out << *next;
    }
    return out;
}

//0 means equal 1 means we're greater than obj, -1 means we're less than obj.
int enode::compare(const text & obj) const
{
    if( obj == keyvalue ) return 0;
    return obj < keyvalue;
}

enode::enode() : event()
{
    next = NULL;
}

enode::enode(const event & new_data, const text & new_keyvalue) : event(new_data)
{
    keyvalue = new_keyvalue;
    next = NULL;
}

enode::enode(const enode & obj) : event(obj)
{
    keyvalue = obj.keyvalue;

    if(obj.next)
        next = new enode(*obj.next);
    else
        next = NULL;
}

enode::~enode()
{
    if( next )
    {
        cout << *next << endl;
        delete next;
        next = NULL;
    }
}

bool enode::operator<(const enode & obj) const
{
    return keyvalue < obj.keyvalue;
}
bool enode::operator>(const enode & obj) const
{
    return keyvalue > obj.keyvalue;
}
bool enode::operator<=(const enode & obj) const
{
    return keyvalue <= obj.keyvalue;
}
bool enode::operator>=(const enode & obj) const
{
    return keyvalue >= obj.keyvalue;
}
