/*
 * Nicholas Grout
 * Program 3
 */
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
/*
 * Since we need comments and keywords in the event, event class would be huge
 * if we tried to handle both of those + everything else. So instead we make a
 * small class called text where we can easily manage arrays of char pointers.
 */

#ifndef TEXT_
#define TEXT_
class text
{
    public:
        text();
        text(const char * new_data);
        text(const text & obj);
        ~text();
        //Ostream incorporation
        friend ostream& operator<<(ostream & out, const text & obj);
        //Insertion operators
        friend text& operator<<(text & obj, const char * new_text);
        friend text& operator<<(text & obj, const text & new_text);
        //Equality operators
        bool operator==(const text & obj) const;
        bool operator!=(const text & obj) const;
        friend bool operator==(const text & obj, const char * test);
        friend bool operator==(const char * test, const text & obj);
        friend bool operator!=(const text & obj, const char * test);
        friend bool operator!=(const char * test, const text & obj);
        //Assignment operator
        text& operator=(const text & obj);
        //Relational operators
        bool operator<(const text & obj) const;
        bool operator>(const text & obj) const;
        bool operator>=(const text & obj) const;
        bool operator<=(const text & obj) const;
    private:
        bool insert(const text & obj);
        bool equals(const char * test) const;
        bool compare(const char * data, const char * test_text) const;
        bool insert(text * obj, text *& head);
        char * data;
        text * next;
};
#endif
