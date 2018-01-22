//Nicholas Grout
//A2
//Prof: Karla Fant
#include "stack_queue.h"

//I honestly couldn't find much use for the stack here. Maybe as the passengers
//enter the plane we can fill up the stacks and have an array of stacks, with
//two for each row. I'm not sure. I've implimented everything here though in
//case the user wants to add it to something.
//
//
//The stack is a circular array, and the size of the array is passed as a
//constructor. I tested it as a row, however I still can't find a use for it
//and I'm not sure what it's suppossed to do based on the assignment so I just
//took it out.

int stack::push( pass & to_add )
{
    if(!top[index].copy(to_add))
        return 0;
    ++index %= row_size;
    return 1;
}

int stack::pop( pass & to_pop )
{
    if( index == 0 )
        return 0;
    --index;
    to_pop.copy( top[index] );
    return 1;
}

int stack::peek( pass & to_peek )
{
    if( index == 0 ) return 0;
    return to_peek.copy( top[index-1] );
}

int stack::pop()
{
    if( index == 0 ) return 0;
    --index;
    return 1;
}
