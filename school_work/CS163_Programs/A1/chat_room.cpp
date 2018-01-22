#include "chat_class.h"

// function to display the chat room info, which also calls a recursive
// function to display all messages of that chat
int chat_room::display()
{
    if( !name || !description || !usernames || !emails) 
        return 0;
    cout << "Name: " << name << endl
         << "Description: " << description << endl
         << "usernames: " << usernames << endl
         << "emails: " << emails << endl;
    // displays all messages of the chat
    return display(message_head);
}

// revursive function to display all messages
int chat_room::display(message * head)
{
    if( !head ) return 0;
    head -> display();
    return display(head -> next) + 1;
}

// Post messages to a chat room. This function takes a message struct
// and a chat room name, and tests the chat room name.
bool chat_room::post(const message & a_message, char * room_name)
{
    // compare the name given to this function to the name of this chat room
    if( !strcmp(room_name, name) )
        return post(a_message);
    // check to see if the next chat room exists. If it doesn't, return
    if( !next )
        return 0;
    else
        // if the name does not match this chat room, and the next chat room
        // exists, go to the next chat room
        return next -> post(a_message,room_name);
}

// function to actually post the message to the chat
bool chat_room::post(const message & a_message)
{
    // create new message node
    message * temp_message = new message;
    if (!(temp_message -> copy(a_message)) )
        return 0;

    // point head to new node if head == NULL
    if( !message_head)
    {
        message_head = temp_message;
        message_tail = message_head;
    }

    // if there's already a message point the tail to the new message node
    else
    {
        message_tail -> next = temp_message;
        message_tail = message_tail -> next;
    }
    return 1;
}

// function to test each message in a chat room to see if the keyword is in
// the message
int chat_room::display_keyword(char * keyword)
{
    if(!message_head) return 0;
    message * current = message_head;
    int count = 0;

    cout << "Chat room: " << name << endl;
    while(current)
    {
        // test the keyword
        if(current -> display_keyword(keyword))
        {
            // if the keyword is in this message, display the message
            current -> display();
            ++count;
        }
        current = current -> next;
    }
    // return how many messages were shown
    return count;
}

// 
bool chat_room::user(char * user)
{
    if(!user || !usernames) return 0;
    int a_user_len = strlen(user);
    int all_user_len = strlen(usernames);
    char * to_test = new char[a_user_len + 1];

    for(int i = 0, j = 0; i < all_user_len; ++i)
    {
        while(user[j] == usernames[i] && j < a_user_len && i < all_user_len)
        {
            to_test[j] = usernames[i];
            to_test[j + 1] = '\0';
            ++i, ++j;
        }
        j = 0;
        if( !strcmp( to_test, user) )
            return 1;
    }
    return 0;
}

bool chat_room::copy(const chat_room & a_room)
{
    if( name ) delete [] name;
    if( description ) delete [] description;
    if( emails ) delete [] emails;
    if( usernames ) delete [] usernames;

    name = new char[strlen(a_room.name) + 1];
    strcpy(name,a_room.name);

    description = new char[strlen(a_room.description) + 1];
    strcpy(description,a_room.description);

    emails = new char[strlen(a_room.emails) + 1];
    strcpy(emails,a_room.emails);

    usernames = new char[strlen(a_room.usernames) + 1];
    strcpy(usernames,a_room.usernames);

    if(a_room.message_head)
    {
        delete message_head;
        message_head = new message;
        message_head -> copy(*a_room.message_head);

        message * a_room_current = a_room.message_head;
        message * local_current;

        while(a_room_current)
        {
            local_current -> next = new message;
            local_current = local_current -> next;
            local_current -> copy(*a_room_current);
            a_room_current = a_room_current -> next;
            message_tail = local_current;
        }
    }
    return 1;
}

// iteratively walks through each message,
// starts recurssively deleting when time test returns 1
// returns the number of messages removed
int chat_room::remove_before(time_t & a_time)
{
    // base case. Empty LLL
    if(!message_head) return 0;
    // 2nd base case. Since messages are appended at the end of the LLL,
    // if the first message is before the indicated time then
    // the rest of the messages will be okay.
    if( !message_head -> test_time(a_time) )
        return 0;

    message * temp = message_head;
    int count = 0;
    // test_time(time_t) returns 1 if the message is older than the time
    // given to it.
    while( message_head -> test_time(a_time) && message_head)
    {
        temp = message_head;
        temp -> delete_this_message();
        temp = NULL;
        message_head = message_head -> next;
        ++count;
    }

    return count;
}
