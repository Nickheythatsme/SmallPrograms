//Nicholas Grout
//A2
//Prof: Karla Fant
#include "stack_queue.h"

// Add a passenger to the queue.
int queue::enqueue( pass & passenger )
{
    node * temp = new node;
    temp -> passenger = new pass;

    if( temp -> passenger -> copy(passenger) < 0 )
        return -1;

    if( !rear )
    {
        rear = temp;
        rear -> next = rear;
    }

    else
    {
        temp -> next = rear -> next;
        rear -> next = temp;
        rear = temp;
    }
    return 1;
}

// Remove a passenger from a queue
int queue::dequeue( pass & passenger )
{
    if( !rear ) return 0;
    if( rear -> next == rear )
    {
        if( passenger.copy(*(rear -> passenger)) < 0)
            return -1;
        delete rear;
        rear = NULL;
        return 1;
    }

    else
    {
        if( passenger.copy(*(rear -> next -> passenger)) < 0 )
            return -1;
        node * temp = rear -> next;
        rear -> next = rear -> next -> next;
        delete temp;
        temp = NULL;
    }

    return 1;
}

//Peek at the next passenger in the queue.
int queue::peek( pass & passenger ) 
{
    if( !rear || !rear -> next -> passenger ) return 0;
    if( passenger.copy(*rear -> next -> passenger) < 0 )
        return -1;
    return 1;
}

// Return 1 if the queue is empty. 0 if not empty.
int queue::isempty()
{
    if( !rear ) return 1;
    return 0;
}
