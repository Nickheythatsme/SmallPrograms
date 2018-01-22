//Nicholas Grout
//Assignment 3
//CS163
//Filename: "application_program.cpp"
//This is the application program which tests and demonstrates the features of
//the hash function.
#include "table.h"
#include <fstream>
#define TEMP 5000
#define DELIM '|'
using namespace std;

int load_events( char * file_name, table & ADT );
int parse_keywords( char * all_keywords, event_s & put_keywords_here);

//Functions to test ADT.
int read_in_event( table & ADT );
int test_retrieve(table & ADT);
int test_display_keyword(table & ADT);
time_t test_remove_before(table & ADT, bool return_time = 0);
int view_collisions( table & ADT );

int menu();

int main(int argc, char ** argv)
{
    //Define the hash table with any 8 byte positive value.
    table ADT(101);
    int choice = 0;

    if(load_events( argv[1], ADT ) < 0)
        cout << "Error loading events" << endl;

    do{
        choice = menu();
        switch ( choice )
        {
            case 1: //Need to impliment 
                if(read_in_event(ADT) < 0)
                    cout << "Error reading in event" << endl;
                break;
            case 2:
                if(test_retrieve(ADT) < 0)
                    cout << "Error retrieving events" << endl;
                break;
            case 3:
                if(test_display_keyword(ADT) < 0)
                    cout << "Error displaying events" << endl;
                break;
            case 4:
                if( ADT.display_all() < 0 )
                    cout << "Error displaying all events" << endl;
                break;
            case 5:
                if( test_remove_before(ADT) < 0)
                    cout << "Error removing events before time" << endl;
                break;
            case 6:
                if( ADT.remove_all() < 0 )
                    cout << "Error removing all nodes" << endl;
                break;
            case 7:
                if( view_collisions(ADT) < 0 )
                    cout << "Error getting collisions from ADT" << endl;
                break;
        }
    }while( choice != 0 );

    return 0;
}

int menu()
{
    int choice = 0;
    cout << endl << endl
         << "1) Make event\n"
         << "2) Search events and return in array (keyword, name, location)\n"
         << "3) Display events matching keyword, name, location\n"
         << "4) Display all events\n"
         << "5) Remove all before a timestamp\n"
         << "6) Remove all\n"
         << "7) View collisions\n"
         << "0) Quit\n"
         << "Choice: ";
    cin >> choice;
    cin.ignore(100,'\n');
    return choice;
}

int load_events( char * file_name, table & ADT )
{
    if( !file_name ) return -1;
    int count = 0;
    char temp[TEMP];
    struct tm temp_time;
    ifstream fin;
    event_s a_event;
    fin.open(file_name);

    //Prime the fstream pump!
    fin.get(temp,TEMP,DELIM);
    fin.ignore(TEMP,DELIM);
    a_event.name = new char[strlen(temp) + 1];
    strcpy( a_event.name, temp );

    while( !fin.eof() )
    {
        //Getting the location here.
        fin.get(temp,TEMP,DELIM);
        fin.ignore(TEMP,DELIM);
        a_event.location = new char[strlen(temp) + 1];
        strcpy( a_event.location, temp );

        //Getting the date here.
        fin.get(temp,TEMP,DELIM);
        fin.ignore(TEMP,DELIM);
        sscanf(temp,"%d-%d-%d", (&temp_time.tm_year), &temp_time.tm_mon - 1,
                &temp_time.tm_mday);
        temp_time.tm_year -= 1900; //The year and the month need to be adjusted
        --temp_time.tm_mon;

        //Getting the time here.
        fin.get(temp,TEMP,DELIM);
        fin.ignore(TEMP,DELIM);
        sscanf(temp,"%d:%d", &temp_time.tm_hour, &temp_time.tm_min);

        //Here we store the time as a unsigned int.
        a_event.time = mktime(&temp_time); 

        //Getting the description here.
        fin.get(temp,TEMP,DELIM);
        fin.ignore(TEMP,DELIM);
        a_event.description = new char[strlen(temp) + 1];
        strcpy( a_event.description, temp );

        //Getting the string of keywords here. Then this string is parsed in
        //another function.
        fin.get(temp,TEMP,'\n');
        fin.ignore(TEMP,'\n');
        if( parse_keywords( temp, a_event ) < 0 )
            return -1;
        
        //Insert the new event into the ADT.
        if( ADT.insert( a_event ) < 0 )
            return -1;

        //This clears the character arrays and avoids memory leaks!
        a_event.clear();
        ++count;

        //Flush the fstream toilet!
        //Getting the name here.
        fin.get(temp,TEMP,DELIM);
        fin.ignore(TEMP,DELIM);
        a_event.name = new char[strlen(temp) + 1];
        strcpy( a_event.name, temp );
    }

    fin.close();
    return count;
}

//Parses the keywords as one array into 0-5 arrays of individual keywords.
int parse_keywords( char * all_keywords, event_s & event )
{
    if( !all_keywords )
        return -1;

    char temp[TEMP];
    char ** temp_keywords = event.keyword;
    int j = 0, count = 0;
    while( *all_keywords)
    {
        if( *all_keywords == ',' && count < 4)
        {
            *temp_keywords = new char[strlen(temp) + 1];
            strcpy( *temp_keywords, temp );

            temp[0] = '\0';
            j = 0;
            ++all_keywords;
            ++temp_keywords;
            ++count;
        }
        temp[j++] = *(all_keywords++);
        temp[j] = '\0';
    }

    *temp_keywords = new char[strlen(temp) + 1];
    strcpy( *temp_keywords, temp );

    return 1;
}

//Read in a new event from the user
int read_in_event( table & ADT)
{
    event_s a_event;
    char temp[200];

    cout << "Enter name: ";
    cin.get(temp,200,'\n');
    cin.ignore(100,'\n');
    a_event.name = new char[strlen(temp) + 1];
    strcpy( a_event.name, temp );

    cout << "Enter location: ";
    cin.get(temp,200,'\n');
    cin.ignore(100,'\n');
    a_event.location = new char[strlen(temp) + 1];
    strcpy( a_event.location, temp );

    cout << "Enter description: ";
    cin.get(temp,200,'\n');
    cin.ignore(100,'\n');
    a_event.description = new char[strlen(temp) + 1];
    strcpy( a_event.description, temp );

    //The function test_remove_before() can also just return a time_t value.
    a_event.time = test_remove_before(ADT, 1);

    for(int i = 0; i < 5; ++i)
    {
        cout << i + 1 << ": ";
        cout << "Enter keyword: ";
        cin.get(temp,200,'\n');
        cin.ignore(100,'\n');

        a_event.keyword[i] = new char[strlen(temp) + 1];
        strcpy( a_event.keyword[i], temp );
    }

    if( ADT.insert( a_event ) < 0 )
        return -1;

    return 1;
}

int test_retrieve(table & ADT)
{
    char temp[TEMP];
    event_s * events = NULL;
    int count = 0;

    cout << "Keyword, name or location: ";
    cin.get(temp, TEMP, '\n');
    cin.ignore(100,'\n');
    count = ADT.retrieve(temp, events);
    if( count < 0 )
        return -1;
    for( int i = 0 ; i < count; ++i )
        events[i].display();
    cout << count << " events found" << endl;
    if( events )
        delete [] events;
    return 1;
}

int test_display_keyword(table & ADT)
{
    char temp[TEMP];
    cout << "Keyword, name or location: ";
    cin.get(temp, TEMP, '\n');
    cin.ignore(100,'\n');
    return ADT.display( temp );
}

time_t test_remove_before(table & ADT, bool return_time)
{
    time_t user_time = time(NULL);
    //We initialize struct so we don't get any crazy garbage values.
    struct tm * temp_struct = localtime( &user_time );
    int year, month, day, hour, min;

    cout << "Year(YYYY): ";
    cin >> year;
    cin.ignore(100,'\n');

    cout << "Month(1-12): ";
    cin >> month;
    cin.ignore(100,'\n');

    cout << "day(1-31): ";
    cin >> day;
    cin.ignore(100,'\n');

    cout << "hour(0-24): ";
    cin >> hour;
    cin.ignore(100,'\n');

    cout << "min(0-60): ";
    cin >> min;
    cin.ignore(100,'\n');

    temp_struct -> tm_year = year - 1900;
    temp_struct -> tm_mon  = month - 1;
    temp_struct -> tm_mday = day;
    temp_struct -> tm_hour = hour;
    temp_struct -> tm_min  = min;

    user_time = mktime( temp_struct );
    if( !return_time )
    {
        cout << "Removing all before: " << ctime( &user_time );
        cout << ADT.remove( user_time ) << " events removed" << endl;
    }

    return user_time;
}

int view_collisions( table & ADT )
{
    int * collisions = NULL;
    int variance = 0;
    int size = ADT.return_collisions( collisions, variance );
    for(int i = 0; i < size; ++i)
        printf("Chain %2d has %3d nodes\n", i, collisions[i]);
    printf("Variance^2: %d\n",variance);
    return size;
}
