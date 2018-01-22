/* Nicholas Grout
 * Professor Karla Fant
 * Assignment 4
 *
 * File name: event.cpp
 *
 * Description: This file contains the implementation of the event struct,
 * including constructors/destructors, copy function and display function.
 */

#include "event.h"

event::event()
{
    name = location = description = NULL;
    keyword = new char * [5];
    for(int i = 0; i < 5; ++i)
        keyword[i] = NULL;
}

event::~event()
{
    //Clear strings and arrays
    clear();
    delete [] keyword;
    keyword = NULL;
}

//Copy a different event's data into this event
int event::copy( event & to_copy )
{
    //Clear this event
    clear();

    //Copy time into this event.
    time = to_copy.time;

    //Copy the char arrays, if there are any.
    if( to_copy.name )
    {
        name = new char[strlen(to_copy.name) + 1];
        strcpy( name, to_copy.name );
    }

    if( to_copy.location )
    {
        location = new char[strlen(to_copy.location) + 1];
        strcpy( location, to_copy.location );
    }

    if( to_copy.description )
    {
        description = new char[strlen(to_copy.description) + 1];
        strcpy( description, to_copy.description );
    }

    //Test each keyword to see if it's set to null. This is how we check
    //for less than 5 keywords.
    for(int i = 0; i < 5 && to_copy.keyword[i]; ++i) 
    {
        keyword[i] = new char[strlen(to_copy.keyword[i]) + 1];
        strcpy( keyword[i], to_copy.keyword[i] );
    }
    return 1;
}

//Clear the events and set each keyword to NULL. This is used by the application
//program so they can keep using the event. I guess they could just use a
//pointer too though.
int event::clear()
{
    char ** temp = keyword;
    if( name )        delete [] name;
    if( location )    delete [] location;
    if( description ) delete [] description;
    name = location = description = NULL;

    for( int i = 0 ; i < 5 && *temp; ++i, ++temp)
    {
        delete [] *temp;
        *temp = NULL;
    }
    time = 0;
    return 1;
}

//Display the details of an event. I use stdio because it's easier to format.
int event::display()
{
    //The 'time' variable in event holds our event's time in seconds since
    //the epoch. This is nice because it's an 8 byte unsigned int, which is
    //good for minimizing space. But it's bad because people can't read a 7
    //digit long number and convert it to a time in their head. We convert it
    //to a string below:

    char time_s[15]; //This is to hold the time formatted as a string.
    char date_s[15]; //This is to hold the date formatted as a string.
    struct tm * timeinfo = gmtime( &time );//Convert time_t to struct tm here.
    //Formatting time as a string below:
    strftime (time_s, 15,"%I:%M%p", timeinfo);
    strftime (date_s, 15,"%F", timeinfo);

    printf("Event name:  %s\n"
           "location:    %s\n"
           "Description: %s\n"
           "Date:        %s\n"
           "Time:        %s\n"
           "Keywords:    ",
            name, 
            location, 
            description,
            date_s,
            time_s);

    for(int i = 0; i < 5 && keyword[i]; ++i)
        printf("%s, ", keyword[i]);

    fflush(stdout);
    printf("\n\n");
    return 1;
}
