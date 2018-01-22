#include "chat_class.h"


//create a new message
bool message::create(char * new_text)
{
    if( !new_text ) return 0;
    if( text )
        delete text;
    time(&the_time);
    text = new char[ strlen(new_text) + 1];
    strcpy(text, new_text);
    return 1;
}

bool message::copy(const message & a_message)
{
    if( !a_message.text ) return 0;
    text = new char[strlen(a_message.text) + 1];
    strcpy(text, a_message.text);
    the_time = a_message.the_time;
    return 1;
}

//display this single message
bool message::display()
{
    if( !text ) return 0;
    cout << " > \"" << text << "\" -" << ctime(&the_time);
    return 1;
}

//return 1 if the keyword is in the message
bool message::display_keyword(char * keyword)
{
    if( !text || !keyword ) return 0;
    int key_len = strlen(keyword);
    int text_len = strlen(text);
    char * to_test = new char[key_len + 1];

    for(int i = 0, j = 0; i < text_len; ++i)
    {
        while(keyword[j] == text[i] && j < key_len)
        {
            to_test[j] = text[i];
            to_test[j + 1] = '\0';
            ++j, ++i;
        }
        j = 0;
        if( !strcmp(keyword, to_test) )
            return 1;
    }
    return 0;
}

// returns 1 if this message is before this time stamp.
bool message::test_time(time_t & a_time)
{
    return ( 0 < difftime(a_time,the_time) );
}

bool message::delete_this_message()
{
    if( text )
        delete [] text;
    text = NULL;
    return 1;
}
