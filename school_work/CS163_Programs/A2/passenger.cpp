//Nicholas Grout
//A2
//Prof: Karla Fant
#include "stack_queue.h"

// Create a new passenger based on a name and row and seat
int pass::create(char * new_name, int new_row, char new_seat)
{
    if( !new_name || !new_row ) return -1;
    if( name )
        delete [] name;

    name = new char[strlen(new_name) + 1];
    strcpy(name, new_name);

    row = new_row;
    seat = new_seat;

    return 1;
}

// Copy the data from another passenger.
int pass::copy( pass & passenger )
{
    if( !passenger.name ) return -1;
    if( name )
        delete [] name;

    name = new char[strlen(passenger.name) + 1];
    strcpy(name, passenger.name);

    row = passenger.row;
    seat = passenger.seat;
    board_num = passenger.board_num;
    return 1;
}

