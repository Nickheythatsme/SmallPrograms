//Nicholas Grout
//A2
//Prof: Karla Fant
#include "stack_queue.h"
#include <fstream>
#include <iostream>
using namespace std;
#define TEMP 20
#define LONGTEMP 1000
#define DELIM '|'

int display_passenger( pass & passenger );
int main_menu( char *& file_name );
int load_passengers(char * file_name, boarding & board);
int test_boarding_passengers( boarding & board );
int power_to(int n);
int convert_to_int(char * str);

int main()
{
    char * file_name = NULL;
    int row_len = main_menu( file_name );
    // initialize the boarding class. This class handles all client interaction
    boarding board( row_len , 10);

    if( load_passengers( file_name , board) < 0 )
    {
        cout << "Error loading passengers\n";
        return 1;
    }
    
    if( test_boarding_passengers( board ) < 0 )
    {
        cout << "Error loading passengers onto plane\n";
        return 1;
    }

    return 0;
}

int main_menu( char *& file_name )
{
    int choice = 0;

    cout << "Which would you like to load?\n"
         << "1) 10 rows with each row 4 passengers long\n"
         << "2) 10 rows with each row 6 passengers long\n";

    cin.width(1);
    cin >> choice;
    cin.ignore(100,'\n');

    switch( choice ) {
        case 1:
            cout << "Loading 4x10_passengers.txt" << endl;
            file_name = new char[ strlen("4x10_passengers.txt") +1];
            strcpy( file_name, "4x10_passenger_list.txt");
            return 4;
        case 2:
            cout << "Loading 6x10 passenger list..." << endl;
            file_name = new char[ strlen("6x10_passengers.txt") + 1];
            strcpy( file_name, "6x10_passenger_list.txt");
            return 6;
        default:
            return -1;
    }
}

int load_passengers(char * file_name, boarding & board)
{
    if( !file_name ) return 0;
    pass passenger;
    char tname[TEMP];
    char trow[TEMP];
    char tseat[TEMP];
    int trow_int = 0;
    char tseat_char = 0;
    ifstream fin;
    fin.open(file_name);

    // Prime the pump.
    fin.get(tname,TEMP,DELIM);
    fin.ignore(TEMP,DELIM);

    fin.get(tseat,TEMP,DELIM);
    fin.ignore(TEMP,DELIM);
    tseat_char = tseat[0];

    fin.get(trow,TEMP,'\n');
    fin.ignore(TEMP,'\n');
    trow_int = convert_to_int(trow);

    while( !fin.eof() )
    {
        if( !passenger.create( tname, trow_int, tseat_char ) )
        {
            cout << "Couldn't create passenger" << endl;
            return -1;
        }

        if( board.enqueue_boarding( passenger ) < 0 )
        {
            cout << "Couldn't create passenger boarding number\n";
            return -1;
        }

        //display_passenger( passenger );

        fin.get(tname,TEMP,DELIM);
        fin.ignore(TEMP,DELIM);

        fin.get(tseat,TEMP,DELIM);
        fin.ignore(TEMP,DELIM);
        tseat_char = tseat[0];

        fin.get(trow,TEMP,'\n');
        fin.ignore(TEMP,'\n');
        trow_int = convert_to_int(trow);
    }

    return board.make_boarding_queue();
}

int convert_to_int(char * str)
{
    if( !str ) return -1;

    int sum = 0;
    int len = strlen(str) - 1;
    int power = 1;
    for(int i = len; i >= 0; --i)
    {
        power = power_to(i);
        sum += ( int( tolower(str[len - i])) - 48) * power;
    }
    return sum;
}

int power_to(int n)
{
    int sum = 1;
    for(int i = 0 ; i < n; ++i)
        sum *= 10;
    return sum;
}

int test_boarding_passengers( boarding & board )
{
    pass a_passenger;
    int i = 0;
    while( !board.isempty() )
    {
        // The below line simulates a person walking up to the gate with the
        // next boarding number.
        a_passenger.board_num = i++;
        // Board the next passenger. board_a_passenger will return a 0 if the
        // wrong passenger tries to join.
        if( !board.board_a_passenger( a_passenger ) )
            cout << "Wrong passenger! Get back in line!" << endl;
        // Display the passenger that just boarded.
        cout << "Now boarding passenger:\n";
        display_passenger( a_passenger );
        cin.ignore(100,'\n');
    }

    return 1;
}

int display_passenger( pass & passenger )
{
    if( !passenger.name ) return 0;
    cout << "Name: " << passenger.name << endl
         << "Row: " << passenger.row << endl
         << "Seat: " << passenger.seat << endl;
    if( passenger.board_num >= 0 )
         cout << "Board num: " << passenger.board_num << endl;
    return 1;
}
