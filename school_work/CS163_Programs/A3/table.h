//Nicholas Grout
//Assignment 3
//CS163
//Filename "table.h"
//This is the header file which contains definitions of the event struct,
//node struct, and the hash table class.
//
//INPUT - event data from 'events.txt' in the following form:
//  name|location|YYYY-MM-DD|HH:MM|description|keyword1,2,3,4,5
//
//OUTPUT - arrange all events into a hash table based on the event name,
//location, and keywords.
#include <cctype>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <ctime>

#ifndef EVENT
#define EVENT
struct event_s
{
    event_s();
    ~event_s();
    char * name;
    char * location;
    char * description;
    //Time is kept as an 8 byte unsigned int to keep size down and to make sure
    //the formate is uniform.
    time_t time; 
    char ** keyword;

    //Copy an event into this event.
    int copy( event_s & to_copy );
    //Display the data in this event.
    int display();
    //Clear the data in this event.
    int clear();
};

struct node
{
    node();
    ~node();
    node * next;
    //The key value stores the name, location, or keyword that refers to this
    //node. In other words, it's the reason why this node is here. It's used
    //to quickly check if a the event we're searching for is pointed to by this
    //node.
    char * keyvalue;
    event_s * event; //The events aren't actually stored in the node since
                     //we have multiple nodes for each event.
};
#endif

#ifdef EVENT
class table
{
    public:
        table(int array_size = 101);
        ~table();
        //insert() inserts a new event into the ADT. Each event is added several
        //times based on how many keywords it has.
        int insert( event_s & to_add_event );
        //This retrieves all events which match a keyword. Return the number of
        //events that matched or -1 if error.
        int retrieve( char * keyword, event_s *& array_of_events);
        //This removes all events before a certain time. Returns the number of events
        //removed.
        int remove( time_t time );
        //Display only certain events based on a keyword. The keyword can be
        //location, keywords, or name of event.
        int display(char * keyword);
        //Display all the events in the ADT.
        int display_all();
        //Return an array with the length of each chain, as well as the 
        //variance^2 of the length of each chain.
        int return_collisions( int *& to_return, int & variance );
        //Remove_all removes all the events in the ADT.
        int remove_all();
    private:
        //This function does the actual work of inserting a new event.
        int insert( event_s * pointer, char * keyvalue );
        //This is the hash function which determines the index value of the
        //keyvalue.
        int function( char * key_value );
        //This function does the work for the wrapper retrieve(). It adds all
        //matching events to a new LLL, then this LLL is turned into an array.
        int retrieve( char * keyword, node *& new_head, node * head);
        //This goes down a chain and removes all events before a certain time.
        int remove( node *& head, time_t time );
        //This goes down the all_events LLL and displays all of them.
        int display_all( node * head );
        //This function remvoes all the nodes in an LLL. It will either delete
        //the event the node points to, or not delete it based on the argument
        //given. This is to prevent double frees.
        int remove_LLL( node *& head, bool delete_events = 0);

        int * collisions; //Track the number of collisions for each array index
        node ** array; //The array of LLLs where nodes are added
        node * all_events;//The LLL of all events. This LLL is mainly used to
                          //prevent double frees, where we can delete this LLL
                          //last and know that nothing else points to its data.
                          //But it can also be used for a display_all function.
        int size; //The size of the hash table array.
};
#endif
