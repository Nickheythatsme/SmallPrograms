//Nicholas Grout
//A2
//Prof: Karla Fant
#include <cctype>
#include <cstring>

// passenger struct to hold passenger data
struct pass
{
    pass();
    ~pass();
    int create( char * new_name, int new_row, char new_seat);
    int copy( pass & passenger );
    char * name;
    char seat;
    int row;
    int board_num;
};

struct node
{
    node();
    ~node();
    node * next;
    pass * passenger;
};

class stack
{
    public:
        stack(int size);
        ~stack();
        int pop( pass & a_passenger );
        int push( pass & a_passenger );
        int peek( pass & to_peek );
        int pop();
    private:
        pass * top;
        int index;
        int row_size;
};


// circular Linked List
class queue
{
    public:
        queue();
        ~queue();
        int enqueue( pass & passenger );
        int dequeue( pass & passenger );
        int peek( pass & passenger );
        int isempty();
        int display();
    private:
        bool remove_all( node * current );
        node * rear;
};

class boarding
{
    public:
        // The number of rows and the length of each row is sent to the
        // class.
        boarding(int row_len, int rows);
        ~boarding();
        // As passengers arrive to pick up their boarding pass, we enter them
        // into the enqueue. This is when a passenger is assigned a boarding
        // number.
        int enqueue_boarding( pass & to_add );
        // This is for passengers entering the plane with their boarding pass.
        // Will return -1 if the wrong passenger is trying to board
        int board_a_passenger( pass & to_add );
        int peek(pass & to_peek);
        int unboard_passengers( pass & to_pop );
        int make_boarding_queue();
        bool isempty();
    private:
        int enqueue_gate();
        // This is the function for determining a passenger's boarding number
        int assign_boarding_num( int row, int seat );
        // This is the maximum row in the aircraft
        int max_row;
        // This is the size of each row (how many seats in a row).
        int row_size;
        // This is an array which represents the boarding order for each row.
        // This ensures that passengers by the window board first, and aisle
        // passengers board last. It is set when the class is initialized.
        int * seat_order;
        // for passengers arriving at gate getting their boarding pass
        queue board;
        // for passengers boarding plane with their boarding pass
        queue gate;
        // This struct handles the stacks in each row. It represents the seats
        // on the plane and will be used when boarding passengers.
        // Array of passengers who have picked up their boarding pass. It is
        // also ordered based on a passenger's boarding number
        pass * passenger_list;
};
