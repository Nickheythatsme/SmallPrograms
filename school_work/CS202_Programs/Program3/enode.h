/*
 * Nicholas Grout
 * Program 3
 */
#include "event.h"


#ifndef ENODE_
#define ENODE_

class enode : public event
{
    public:
        enode();
        enode(const enode & obj);
        enode(const event & new_data, const text & new_keyvalue);
        ~enode();
        enode& operator=(const enode & obj);
        bool operator<(const enode & obj) const;
        bool operator>(const enode & obj) const;
        bool operator<=(const enode & obj) const;
        bool operator>=(const enode & obj) const;
        friend ostream& operator<<(ostream & out, const enode & obj);
        friend enode& operator<<(enode & obj, const enode & new_node);
        bool set_key(const char * key);
        bool set_event(const event & obj);
        ostream& display(ostream & out) const;
    private:
        int compare(const text & obj) const;
        enode * next;
        text keyvalue;
};

#endif
