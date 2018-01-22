/*
 * Nicholas Grout
 * Program 3
 */
#include "event.h"
#define TEMP 1000
//Insert a new keyword. This makes a new char* array of keywords. That means
//we have to use shifting.
//TODO
bool event::insert_keyword(const char * new_keyword)
{
    keywords << new_keyword;
    return true;
}

//TODO
bool event::insert_comment(const char * new_comment)
{
    comments << new_comment;
    return true;
}

ifstream& operator>>(ifstream & in, event & obj)
{
    text temp_name;
    text temp_phone;
    contact * temp_contact = NULL;
    //bool temp_response;

    //Clear everything from obj.
    event temp_event;
    obj = temp_event;

    //Get name
    obj.read_in(in, obj.name);

    //Get location
    obj.read_in(in, obj.location);

    //Get time
    in >> obj.time;
    in.ignore(TEMP,'|');

    obj.read_in(in, obj.keywords,'|');
    obj.read_in(in, obj.comments,'|');

    do{
        temp_name = text();
        temp_phone = text();
        obj.read_in( in, temp_name );
        obj.read_in( in, temp_phone, '&');
        temp_contact = new contact(temp_name, temp_phone,0);
        obj << *temp_contact;
        delete temp_contact;
        temp_contact = NULL;
    }while( !in.eof() && in.peek() != '\n' );

    return in;
}

//OSTREAM incorporation here
ostream& operator<<(ostream & out, const event & obj)
{
    return obj.display(out);
}

//Displays all the data in this event into the speficied ostream
ostream& event::display(ostream & out) const
{
    out << ">Event name: " << name << endl
        << ">Event location: " << location << endl
        << ">Attendees: " << endl;
    contact_group::display(out);
    out << endl << endl
        << ">Comments: " << endl << comments << endl << endl
        << ">Keywords: " << endl << keywords; 
    return out;
}

//CONSTRUCTOR
event::event(const char * new_name, const char * new_location, time_t new_time) :
    contact_group()
{
    name = new_name;
    location = new_location;

    time = new_time;
}

//DEFAULT CONSTRUCTOR
event::event() : contact_group()
{
    time = 0;
}

//COPY CONSTRUCTOR
event::event(const event & obj) : contact_group(obj)
{
    name = obj.name;
    location = obj.location;
    keywords = obj.keywords;
    comments = obj.comments;

    time = obj.time;
}

//DESTRUCTOR
//TODO include write function
event::~event()
{
    //write()
}

#undef TEMP
