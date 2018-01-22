#include "chat_class.h"

message::message()
{
    text = NULL;
    next = NULL;
}

message::~message()
{
    if( text )
        delete [] text;
    text = NULL;
    
    delete next;
    next = NULL;
}

chat_room::chat_room()
{
    name = description = usernames = emails = NULL;
    message_head = message_tail = NULL;
}

chat_room::~chat_room()
{
    if( name )
        delete [] name;
    if( description )
        delete [] description;
    if( usernames )
        delete [] usernames;
    if( emails )
        delete [] emails;
    name = description = usernames = emails = NULL;

    delete message_head;
    message_head = NULL;
}

cs_chat::cs_chat()
{
    head = tail = NULL;
}
cs_chat::~cs_chat()
{
    delete head;
    head = NULL;
}
