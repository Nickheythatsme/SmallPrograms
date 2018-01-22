//Nicholas Grout
//A2
//Prof: Karla Fant
#include "stack_queue.h"

// As people arrive, this function assigns them a boarding number and adds them
// to the queue of passengers.
int boarding::enqueue_boarding( pass & to_add )
{
    to_add.board_num = assign_boarding_num( to_add.row, to_add.seat - 65 );
    if( board.enqueue( to_add ) < 0 )
        return -1;

    if( passenger_list[to_add.board_num].copy( to_add ) < 0 )
        return -1;
    return to_add.board_num;
}

// Assign a boarding number to a person.
int boarding::assign_boarding_num( int row, int seat )
{
    return ( (max_row - row) * row_size) + seat_order[seat];
}

// Fill the queue of passengers who are waiting to board the plane. This will
// be in order of boarding number.
int boarding::make_boarding_queue()
{
    pass test_pass;
    for(int i = 0; i < (max_row * row_size); ++i)
    {
        // Catch any blank spots from passengers not picking up their boarding
        // pass.
        if( passenger_list[i].name )
        if( gate.enqueue( passenger_list[i] ) < 0 )
            return -1;
    }

    return 1;
}

// Board a passenger who has their boarding pass. Return 0 if it's the wrong
// passenger.
int boarding::board_a_passenger( pass & to_add )
{
    pass test_passenger;
    gate.peek(test_passenger);

    if( test_passenger.board_num == to_add.board_num )
        return gate.dequeue( to_add );
    else
        return 0;
}

int boarding::peek(pass & to_peek)
{
    return gate.peek( to_peek );
}
bool boarding::isempty()
{
    return gate.isempty();
}
