/*
 * Nicholas Grout
 * Program 3
 */
#include "contact.h"

//This changes the state of a contact, if they're attending this event or not.
bool contact::attending(bool new_response)
{
    if( new_response )
        response = 1;
    else
        response = -1;
    return true;
}

//This is the implementation of the assignment operator. Now we can simply do
//contact1 = contact2 and not worry about deleting contact1's data and copying
//it over.
contact& contact::operator=(const contact & obj)
{
    if( this == &obj ) return *this;
    //Copy the name data (delete it if it's already there).
    name = text(obj.name);
    phone = text(obj.phone);
    response = obj.response;

    return *this;
}

//This is the dispaly all function. It displays both the number and the name
//of the contact.
ostream& contact::display(ostream & out) const
{
    //TODO finish formatting. We want almost all names and phone numbers to
    //line up with each other on new lines.
    out << name << '\t' << phone;
    out << '\t';
    if( response == 1 )
        out << "Attending";
    if( response == -1 )
        out << "Not attending";
    if( response == 0 )
        out << "Maybe attending";
    return out;
}

//Here the is friend function for the insertion into ostream operator. This
//allows us to put cout << contact; without issue.
ostream& operator<<(ostream & out, const contact & obj)
{
    obj.display(out);
    return out;
}

bool contact::operator==(const contact & obj)
{
    if( this == &obj ) return true;
    if( name == obj.name || phone == obj.phone )
        return true;
    return false;
}

//This compares the name or number. Returns TRUE if either match.
bool contact::operator==(const char * test) const
{
    if( name == test || phone == test )
        return true;
    return false;
}

contact& contact::operator++(void)
{
    response = 1;
    return *this;
}

contact& contact::operator--(void)
{
    response = -1;
    return *this;
}

//This is the DEFAULT CONSTRUCTOR for the contact class.
contact::contact()
{
    response= 0;
}

contact::contact(const text & n_name, const text & n_phone, bool n_response)
{
    response = n_response;
    name = n_name;
    phone = n_phone;
}

//This is the CONSTRUCTOR for the contact class.
contact::contact(const char * new_name, const char * new_phone)
{
    name = new_name;
    phone = new_phone;
    response = 0;
}

//This is the COPY CONSTRUCTOR for the contact class.
contact::contact(const contact & obj)
{
    name = obj.name;
    phone = obj.phone;
    response = obj.response;
}

//This is the DESTRUCTOR for the contact class.
contact::~contact()
{
}
