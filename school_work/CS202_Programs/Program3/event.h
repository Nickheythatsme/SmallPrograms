/*
 * Nicholas Grout
 * Program 3
 */
#include "contact/contact_group.h"
#include <time.h>

#ifndef EVENT_
#define EVENT_

class event : public contact_group
{
    public:
        event();
        event(const char * name, const char * location, time_t time);
        event(const event & obj);
        ~event();
        bool insert_keyword(const char * new_keyword);
        bool insert_comment(const char * new_comment);
        friend ostream& operator<<(ostream & out, const event & obj);
        friend ifstream& operator>>(ifstream & in, event & obj);
        friend event& operator<<(event & obj, const contact_group & group);
    protected:
        ostream& display(ostream & out) const;
    private:
        //group of people is inherited.
        time_t time;
        text name;
        text location;
        text keywords;
        text comments;
};

#endif
