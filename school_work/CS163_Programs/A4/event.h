/* Nicholas Grout
 * Professor: Karla Fant
 * Assignment 4
 *
 * File name: event.h
 *
 * Description: This file contains the definition of the event struct. It has 
 * all of the functions and objects used by the event struct.
 *
 */

#include <cctype>
#include <stdio.h>
#include <cstring>
#include <ctime>

#ifndef EVENT
#define EVENT
struct event
{
    event();
    ~event();
    char * name;
    char * location;
    char * description;
    //Time is kept as an 8 byte unsigned int to keep size down and to make sure
    //the formate is uniform.
    time_t time; 
    char ** keyword;

    //Copy an event into this event.
    int copy( event & to_copy );
    //Display the data in this event.
    int display();
    //Clear the data in this event.
    int clear();
};
#endif
