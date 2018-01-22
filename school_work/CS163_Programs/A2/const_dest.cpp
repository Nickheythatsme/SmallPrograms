//Nicholas Grout
//A2
//Prof: Karla Fant
#include "stack_queue.h"

pass::pass()
{
    name = NULL;
    seat = ' ';
    row = -1;
    board_num = -1;
}

pass::~pass()
{
    if( name )
        delete [] name;
    name = NULL;
}

node::node()
{
    next = NULL;
    passenger = NULL;
}

node::~node()
{
    next = NULL;
    if( passenger )
        delete  passenger;
    passenger = NULL;
}


stack::stack(int size)
{
    top = new pass[size];
    index = 0;
    row_size = size;
}

stack::~stack()
{
    if( top )
        delete [] top;
    top = NULL;
}

queue::queue()
{
    rear = NULL;
}

queue::~queue()
{
    if( rear && rear == rear -> next )
        delete rear;
    if( rear )
    {
        node * current = rear -> next;
        rear -> next = NULL;
        remove_all(current);
    }
    rear = NULL;
}

bool queue::remove_all( node * current )
{
    if( !current ) return 0;
    remove_all( current -> next );
    delete current;
    current = NULL;
    return 1;
}

boarding::boarding(int number_of_seats,
        int number_of_rows)
{
    max_row = number_of_rows; //number of rows on the plane
    row_size = number_of_seats; //number of seats in a row 

    seat_order = new int[row_size - 1];
    for(int i = 0; i < row_size; ++i)
    {
        if( i < (row_size/2) )
            seat_order[i] = 2*i;
        else
            seat_order[i] = (-2*i) + (2*row_size)-1;
    }

    // This array is a list of passengers. It is the intermediary between the
    // boarding queueu and the passengers entering the plane queue. 0 to 1 less
    // than the maximum seat (because of 0 index).
    passenger_list = new pass [ (max_row * row_size)];
}

boarding::~boarding()
{

    delete [] passenger_list;
    passenger_list = NULL;
}
