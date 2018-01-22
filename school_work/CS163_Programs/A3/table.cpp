//Nicholas Grout
//Assignment 3
//CS163
//Filename: "table.cpp"
//This is the implementation of the table class. It contains a constructor and 
//a destructor, as well as the implementation of the class's member functions.
#include "table.h"

table::table(int array_size)
{
    //This prevents the array size from being initialized to an invalid size.
    if( array_size < 1 ) size = 101;
    size = array_size;
    all_events = NULL;
    array = new node * [size];//array = new node * [size] {NULL} for c++11
    collisions = new int[size];

    int * current_int = collisions;
    node ** current = array;//We use temporary pointers rather than
                            //shifting through array[i] each time.
    for(int i = 0; i < size; ++current, ++i)
    {
        *current = NULL;
        *current_int = 0;
    }
}

table::~table()
{
    delete [] collisions;
    collisions = NULL;

    node ** current = array;
    for(int i = 0; i < size; ++current, ++i)
    {
        remove_LLL( *current, 0 );
        *current = NULL;
    }
    remove_LLL( all_events, 1 );
    all_events = NULL;
    delete [] array;
    array = NULL;
}

//Remove all the nodes in the LLL, the 'delete_events' variable indicates
//whether or not the event the node's event_s pointer points to should also be 
//deleted.
int table::remove_LLL( node *& head, bool delete_events )
{
    if( !head ) return 0;
    remove_LLL( head -> next, delete_events);
    if( delete_events )
        delete head -> event;
    head -> event = NULL;
    delete head;
    head = NULL;
    return 1;
}

//Insert a new event into the table. This function calls another insert function
//with each keyword/title/location. It also creates a new node for the event. 
int table::insert( event_s & event )
{
    int count = 0;
    //Create new node with new event.
    node * new_node = new node;
    new_node -> event = new event_s;
    //The new event is copied so we don't lose it.
    if( new_node -> event -> copy( event ) < 0 )
        return -1;
    //Create temporary pointer to the new event
    event_s * temp_event = new_node -> event; 

    //Store the new node in the LLL.
    new_node -> next = all_events;
    all_events = new_node;

    if( insert( temp_event, event.name ) > 0)
        ++count;
    if( insert( temp_event, event.location ) > 0)
        ++count;
    for( int i = 0; i < 5 && event.keyword[i]; ++i, ++count)
        insert( temp_event, event.keyword[i] );

    return count;
}

//Called by other insert function. This function does the acutal insertion.
int table::insert( event_s * pointer, char * keyvalue )
{
    if( !keyvalue ) return -1;
    int value = function( keyvalue );

    node * temp = new node;
    temp -> event = pointer;
    temp -> keyvalue = new char[strlen(keyvalue) + 1];
    strcpy( temp -> keyvalue, keyvalue );

    temp -> next = array[value];
    array[value] = temp;

    ++collisions[value];//Update the nuber of collisisions at that index.
    return value;
}

//Determine the index value of the keyvalue sent to this function.
int table::function( char * keyvalue )
{
    //Since we're dealing with smaller hash values, the bytes we really care
    //about are probably the last 2 (maybe 3) bytes. However if we shift
    //the keyvalue to a different position, we can use all 4 bytes of the
    //unsigned int.
    if( !keyvalue ) return -1;
    unsigned int hash = 0;
    int place = 0;

    //This is faster than a for loop, and allows us to create
    //more distinct hash values because we use each character and each byte.
    while( *keyvalue )
    {
        hash += *keyvalue << place;
        ++keyvalue, ++place;
        place %= 32;
    }
    hash = hash >> 1;
    return hash %= size;
}

//Return an array with the length of each chain, as well as the variance^2 of
//the length of each chain.
int table::return_collisions( int *& to_return, int & variance )
{
    if( to_return )
        delete [] to_return;
    int sum = 0;//Sum of all the collisions at each index.
    int mean = 0;//Mean of the length of each chain.
    to_return = new int[size];
    for( int i = 0; i < size; ++i)
        sum += to_return[i] = collisions[i];
    
    mean = sum/size;
    sum = 0;//Now sum is used for variance
    for(int i = 0; i < size; ++i)
        sum += (collisions[i] - mean) * (collisions[i] - mean);
    variance = sum/(size - 1); //This value is the variance^2.
    
    return size;
}

//Retrieve all events with a matching keyword and 
//return an array of these events.
int table::retrieve( char * keyword, event_s *& events )
{
    if( !keyword ) return -1;
    if( events )
        delete [] events;
    int count = 0;
    
    node * new_head = NULL; //Contains a list of all the matching events.
    count = retrieve( keyword, new_head, array[ function(keyword) ] );
    if( !count ) return count;
    events = new event_s[count];
    for(int i = 0; i < count; ++i)
    {
        events[i].copy( *(new_head -> event) );
        new_head = new_head -> next;
    }
    return count;
}

//Recursively add all events in a LLL to the array
int table::retrieve( char * keyword, node *& new_head, node * head)
{
    if( !head ) return 0;
    if( !strcmp(keyword, head -> keyvalue) )
    {
        new_head = new node;
        new_head -> event = head -> event;
        return retrieve( keyword, new_head -> next, head -> next) + 1;
    }
    else
        return retrieve( keyword, new_head, head -> next);
}

int table::display( char * keyword )
{
    if( !keyword ) return 0;
    int count = 0;
    node * new_head = NULL; //Contains a list of all the matching events.

    count = retrieve( keyword, new_head, array[ function(keyword) ] );
    if( count <= 0 )
        return 0;

    while( new_head )
    {
        new_head -> event -> display();
        new_head = new_head -> next;
    }
    return count;
}

//Display all the events in the ADT.
int table::display_all()
{
    return display_all( all_events );
}

//Display all the events in an LLL, recursively.
int table::display_all(node * head)
{
    if( !head ) return 0;
    head -> event -> display();
    return display_all(head -> next) + 1;
}

//Remove all events before a time.
int table::remove( time_t time )
{
    node ** current = array;
    for(int i = 0; i < size; ++i)
        //This is removing event pointers from the chains. Also updating
        //the int array that keeps track of collisions.
        collisions[i] -= remove(*(current++), time );
    //I have all events copied in an LLL called 'all_events' to help prevent
    //double frees.
    return remove( all_events, time );
}

//Remove all events before a time recursively.
int table::remove( node *& head, time_t time )
{
    if( !head || !head -> next ) return 0;
    //Traverse to the end of the chain
    int count = remove( head -> next, time );
    
    //This tests if the event time is before the time given.
    if( difftime(head -> next -> event -> time, time) < 0 )
    {
        node * temp = head -> next -> next;
        delete head -> next;
        head -> next = temp;
        return ++count;
    }
    return count;
}

//This removes all the events from an ADT.
int table::remove_all()
{
    node ** current = array;
    for(int i = 0; i < size; ++current, ++i)
    {
        remove_LLL( *current, 0 );
        collisions[i] = 0;
        *current = NULL;
    }
    remove_LLL( all_events, 1 );
    all_events = NULL;
    return 1;
}
