//Nicholas Grout
//Assignment 3
//CS163
//Filename: "node.cpp"
//This is the implementation of the node struct. It contains a constructor and a
//destructor.
#include "table.h"

node::node()
{
    keyvalue = NULL;
    next = NULL;
    event = NULL;
}

node::~node()
{
    if( keyvalue )
        delete [] keyvalue;
    //The keyvalue is used when searching for a keyword, name, or location.
    //This way we know why the node was put into the list, and can easily
    //search for it.
    keyvalue = NULL;
    next = NULL;
    //The event must be deleted manually. This is to prevent double frees and
    //seg faults.
    event = NULL;
}
