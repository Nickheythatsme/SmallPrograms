/* Nicholas Grout
 * Professor Karla Fant
 * Assignment 4
 *
 * File name: application_program.cpp
 *
 * Description: This file contains the the application of the tree class,
 * including functions to load events from a file and functions to test
 * features of the tree class. Some functions in this file also use the
 * event struct.
 *
 */

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include "event.h"
#include "tree.h"
#define TEMP 2000
#define DELIM '|'
using namespace std;

//Used for loading comments
int num_events(char * file_name);
//Used for loading comments
int load_events( char * file_name, event *& array_of_events);
//Used for loading comments
int parse_keywords( char * all_keywords, event & put_keywords_here);

//This tests tree's retrieve feature.
int retrieve( tree & BST );
//This tests tree's remove by name feature.
int remove(tree & BST);
//This tests the tree's remove by keyword feature.
int remove_keyword(tree & BST);

int main(int argc, char ** argv)
{
    event * events = NULL;
    char * file_name = NULL;
    int count = 0;
    tree BST;
    if( argc <= 1 )
    {
        file_name = new char[strlen("list_of_events.txt") + 1];
        strcpy(file_name,"list_of_events.txt");
    }
    else
        file_name = argv[1];

    count = load_events(file_name, events);
    if( count < 0 )
    {
        cout << "Error loading events\n";
        return EXIT_FAILURE;
    }
    else
        cout << count << " loaded from: " << file_name << endl;
    for(int i = 0; i < count; ++i)
        BST.insert(events[i]);

    //Call the tree's display all function.
    //BST.display_all();
    cout << "height: " << BST.return_height() << endl;

    if( retrieve( BST ) <= 0 )
        cout << "Event not found" << endl;
    if( remove( BST ) <= 0 )
        cout << "Error removing event or event not found" << endl;
    cout << "Number of events removed: " << remove_keyword( BST ) << endl;

    if( argc <= 1 )
    {
        delete [] file_name;
        file_name = NULL;
    }
    delete [] events;
    events = NULL;
    return EXIT_SUCCESS;
}

//This just counts the number of new lines in the file, which corresponds to 
//the number of events in the file. It is used to size the array of events.
int num_events(char * file_name)
{
    int lines = 0;
    ifstream fin;
    fin.open(file_name);
    if(!fin) return -1;

    while( !fin.eof() )
    {
        fin.ignore(TEMP,'\n');
        ++lines;
    }
    fin.close();
    return --lines;
}

int load_events( char * file_name, event *& array_of_events )
{
    if( !file_name ) return -1;
    char temp[TEMP];
    struct tm temp_time;
    int count = num_events(file_name);
    if( count < 0 ) return -1;
    int current_event = 0;

    ifstream fin;
    fin.open(file_name);
    if(!fin) return -1;
    
    if(array_of_events)
        delete [] array_of_events;
    array_of_events = new event[count];
    event * current = array_of_events;

    //Prime the fstream pump!
    fin.get(temp,TEMP,DELIM);
    fin.ignore(TEMP,DELIM);
    current -> name = new char[strlen(temp) + 1];
    strcpy( current -> name, temp );

    while( !fin.eof() && current_event < count )
    {
        //Getting the location here.
        fin.get(temp,TEMP,DELIM);
        fin.ignore(TEMP,DELIM);
        current -> location = new char[strlen(temp) + 1];
        strcpy( current -> location, temp );

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
        current -> time = mktime(&temp_time); 

        //Getting the description here.
        fin.get(temp,TEMP,DELIM);
        fin.ignore(TEMP,DELIM);
        current -> description = new char[strlen(temp) + 1];
        strcpy( current -> description, temp );

        //Getting the string of keywords here. Then this string is parsed in
        //another function.
        fin.get(temp,TEMP,'\n');
        fin.ignore(TEMP,'\n');
        if( parse_keywords( temp, *current ) < 0 )
            return -1;

        ++current;
        ++current_event;

        //Flush the fstream toilet!
        //Getting the name here.
        fin.get(temp,TEMP,DELIM);
        fin.ignore(TEMP,DELIM);
        current -> name = new char[strlen(temp) + 1];
        strcpy( current -> name, temp );
    }
    //This removes the last character in the file and prevents literally
    //1 byte of memory from leaking.
    delete [] current -> name;
    current -> name = NULL;
    fin.close();
    return current_event;
}

//Parses the keywords as one array into 0-5 arrays of individual keywords.
int parse_keywords( char * all_keywords, event & a_event )
{
    if( !all_keywords )
        return -1;

    char temp[TEMP];
    char ** temp_keywords = a_event.keyword;
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

    return count;
}

int retrieve( tree & BST )
{
    char temp[TEMP];
    event * to_retrieve = NULL;
    cout << "Enter event name to display: ";
    cin.get(temp, TEMP, '\n');
    cin.ignore(TEMP,'\n');

    if( BST.retrieve(temp, to_retrieve) < 1 )
    {
        delete to_retrieve;
        to_retrieve = NULL;
        return 0;
    }
    to_retrieve -> display();

    delete to_retrieve;
    to_retrieve = NULL;
    return 1;
}

int remove( tree & BST )
{
    char temp[TEMP];
    cout << "Enter event name to remove: ";
    cin.get(temp, TEMP, '\n');
    cin.ignore(TEMP,'\n');
    return BST.remove_name(temp);
    return 1;
}

int remove_keyword( tree & BST )
{
    char temp[TEMP];
    int count = 0;
    cout << "Enter event keyword to remove: ";
    cin.get(temp, TEMP, '\n');
    cin.ignore(TEMP,'\n');
    count = BST.remove_keyword(temp);
    return count;
}
