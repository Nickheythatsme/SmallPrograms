/*
 * Nicholas Grout
 * Program 3
 */
#include "../text.h"

#ifndef CONTACT_
#define CONTACT_

class contact
{
    public:
        contact(const char * name, const char * phone_num);
        contact(const text & name, const text & phone, bool reponse);
        contact();
        contact(const contact & obj);
        ~contact();
        ostream& display(ostream & out) const;
        //Assignment operator. This allows us to use contact1 = contact2
        contact& operator=(const contact & obj);
        friend ostream& operator<<(ostream & out, const contact & obj);
        bool operator==(const contact & obj);
        bool operator==(const char * name_or_num) const;
        contact& operator++(void);
        contact& operator--(void);
        bool attending(bool response);
    protected:
    private:
        int response; //This is the response 0 is don't know, -1 is no, 1 is yes
        text name;
        text phone;
};

#endif
