#include "chat_class.h"

int cs_chat::display_room_names()
{
    if(!head) return 0;
    chat_room * current = head;
    int count = 1;

    while(current)
    {
        cout << current -> name;
        if( current -> next )
            cout << " | ";
        else 
            cout << endl;
        current = current -> next;
        ++count;
    }
    return count;
}

bool cs_chat::display(char * name)
{
    if(!head) return 0;
    chat_room * current = head;
    while(current)
    {
        if( !strcmp(current -> name, name) )
        {
            if(!current -> display())
                return 0;
            return 1;
        }
        current = current -> next;
    }
    return 0;
}

int cs_chat::display_keyword(char * keyword)
{
    if(!head) return 0;
    chat_room * current = head;
    int count = 0;

    while(current)
    {
        count += current -> display_keyword(keyword);
        current = current -> next;
    }
    cout << "The word \"" << keyword << "\" appears: " << count;
    return count;
}

bool cs_chat::post(const message & a_message, char * room_name)
{
    if(!head) return 0;
    return head -> post(a_message,room_name);
}

int cs_chat::user(char * username)
{
    if(!head) return 0;
    chat_room * current = head;
    int count = 0;

    cout << username << " is present in the following chat rooms:\n";
    while(current)
    {
        if( current -> user(username) )
        {
            cout << current -> name << ", ";
            ++ count;
        }
        current = current -> next;
    }
    cout << endl;
    return count;
}

bool cs_chat::add_room(chat_room & a_room)
{
    chat_room * new_room = new chat_room;
    if( !new_room -> copy(a_room) )
        return 0;

    if(!head)
    {
        head = new_room;
        tail = new_room;
    }
    else
    {
        tail -> next = new_room;
        tail = tail -> next;
    }
    new_room = NULL;
    return 1;
}

int cs_chat::remove_before(time_t & a_time)
{
    if(!head) return 0;
    int count = 0;
    chat_room * current = head;
    while(current)
    {
        count += current -> remove_before(a_time);
        current = current -> next;
    }
    return count;
}
