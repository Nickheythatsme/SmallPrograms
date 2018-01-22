#include <iostream>
#include <cctype>
#include <cstring>
#include <ctime>
using namespace std;

//class to hand the a message's data
class message
{

    public:
        message();
        ~message();
        message * next;
        bool display();
        bool display_keyword(char * keyword);
        bool create(char * text);
        bool copy(const message & a_message);
        bool test_time(time_t & a_time);
        bool delete_this_message();
    private:
        char * text;
        time_t the_time;
};

//chat room struct
struct chat_room
{
    chat_room();
    ~chat_room();
    chat_room * next;

    int display();
    bool copy(const chat_room & a_room);
    int display(message * head);
    int display_keyword(char * keyword);
    bool post(const message & a_message, char * room_name);
    bool post(const message & a_message);
    bool user(char * username);
    int remove_before(time_t & a_time);

    char * name;
    char * description;
    char * usernames;
    char * emails;

    message * message_head;
    message * message_tail;
};

//main class for the CS_chat. Functions are listed below
class cs_chat
{
    public:
        cs_chat();
        ~cs_chat();
        bool display(char * chat_room_title);
        int display_keyword(char * keyword);
        bool post(const message & a_message, char * target_room_name);
        int user(char * username);
        bool add_room(chat_room & a_room);
        int display_room_names();
        int remove_before(time_t & a_time);
    private:
        chat_room * head;
        chat_room * tail;
};
