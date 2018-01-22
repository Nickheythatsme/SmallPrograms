#include "chat_class.h"
const int TEMP = 1000;

// display a menu for the user
int main_menu();
// function which gets a message or name from the user
void get_message(char * & text);
// function to test the add room feature of the cs_chat class
void add_room( cs_chat & a_chat );
// function to test the post message feature of the cs_chat class
void post_message( cs_chat & a_chat);
// function to test the display chat feature of the cs_chat class
void display_a_chat(cs_chat & a_chat);
// function to test the find user feature of the cs_chat class
void find_user( cs_chat & a_chat );
// feature to display all messages with a certain keyword
void display_keyword(cs_chat & a_chat);
// functin to remove all messages before a certain time
void remove_before(cs_chat & a_chat);

int main()
{
    cs_chat chat;
    int choice = 0;

    do{
        choice = main_menu();
        switch( choice )
        {
            case 1:
                add_room(chat);
                break;
            case 2:
                post_message(chat);
                break;
            case 3:
                find_user(chat);
                break;
            case 4:
                display_keyword(chat);
                break;
            case 5:
                display_a_chat(chat);
                break;
            case 6:
                remove_before(chat);
                break;
        }
    }while(choice);
    return 0;
}

int main_menu()
{
    int choice = 0;
    cout << "\n\nChoose an option:\n"
         << "1) Add chat\n"
         << "2) Post a message to a chat\n"
         << "3) Find a user in chats\n"
         << "4) Find a keyword in all chats\n"
         << "5) Display messages from a chat\n"
         << "6) Remove all messages before a time\n"
         << "0) Quit\n";
    cin >> choice;
    cin.ignore(100,'\n');
    return choice;
}

void get_message(char * & text)
{
    char temp[TEMP];
    if( text )
        delete [] text;
    text = NULL;

    cin.get(temp, TEMP, '\n');
    cin.ignore(100,'\n');
    text = new char[strlen(temp) + 1];
    strcpy(text,temp);
    return;
}

void add_room(cs_chat & a_chat)
{
    chat_room a_room;
    char * temp = NULL;

    cout << "Enter chat room name: \n";
    get_message(temp);
    a_room.name = new char[strlen(temp) + 1];
    strcpy(a_room.name, temp);

    cout << "Enter description: " << endl;
    get_message(temp);
    a_room.description = new char[strlen(temp) + 1];
    strcpy(a_room.description,temp);

    cout << "Enter user emails: " << endl;
    get_message(temp);
    a_room.emails = new char[strlen(temp) + 1];
    strcpy(a_room.emails,temp);
    
    cout << "Enter user usernames: " << endl;
    get_message(temp);
    a_room.usernames = new char[ strlen(temp) + 1];
    strcpy(a_room.usernames,temp);

    if( !a_chat.add_room(a_room) )
        cout << "error adding room" << endl;

    if( temp )
        delete [] temp;
    temp = NULL;
    return;
}


void post_message(cs_chat & a_chat)
{
    message new_message;
    char * text = NULL;
    char name[TEMP];

    cout << "Which chat room?\n";
    a_chat.display_room_names();
    cin.get(name,TEMP,'\n');
    cin.ignore(100,'\n');

    cout << name << " > ";
    get_message(text);
    if( !new_message.create(text) )
        cout << "error creating message" << endl;
    if( !a_chat.post(new_message,name) )
        cout << "error posting message to \"" << name << "\"\n";

    if( text )
        delete [] text;
    text = NULL;
    return;
}

void display_a_chat(cs_chat & a_chat)
{
    char * text = NULL;
    if(!a_chat.display_room_names())
        cout << "no rooms to be displayed\n";
    get_message(text);
    if(!a_chat.display(text))
        cout << "no messages in \"" << text << "\"" << endl;

    if( text )
        delete [] text;
    text = NULL;
    return;
}

void find_user( cs_chat & a_chat )
{
    char * text = NULL;
    cout << "Enter username: ";
    get_message(text);
    if ( !a_chat.user(text) )
        cout << "user not found in any chats..." << endl;
    return;
}

//int display_keyword(char * keyword);
void display_keyword(cs_chat & a_chat)
{
    char * text = NULL;
    cout << "Enter keyword to find: ";
    get_message(text);
    if( !a_chat.display_keyword(text) )
        cout << "Keyword not found" << endl;

    if( text )
        delete [] text;
    text = NULL;
    return;
}

void remove_before(cs_chat & a_chat)
{
    time_t now;
    time(&now);
    struct tm  * a_time;
    a_time = localtime(&now);
    int hours, minutes, seconds;
    char time_text[TEMP];

    strftime(time_text,10,"%H:%M:%S",a_time);

    cout << "Current time: " <<  time_text << endl;
    cout << "How many long before this time should messages be kept?\n"
        << "(seconds, minutes, hour)\n";

    cout << "hours: ";
    cin >> hours;
    cin.ignore(100,'\n');

    cout << "minutes: ";
    cin >> minutes;
    cin.ignore(100,'\n');

    cout << "seconds: ";
    cin >> seconds;
    cin.ignore(100,'\n');

    a_time -> tm_min -= minutes;
    a_time -> tm_hour -= hours;
    a_time -> tm_sec -= seconds;

    now = mktime( a_time );
    a_chat.remove_before(now);

    return;
}
