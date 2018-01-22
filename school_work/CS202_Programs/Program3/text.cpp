/*
 * Nicholas Grout
 * Program 3
 */
#include "text.h"
bool text::operator==(const text & obj) const
{
    return equals(obj.data);
}

bool text::operator!=(const text & obj) const
{
    return !equals(obj.data);
}

bool operator==(const text & obj, const char * test)
{
    return obj.equals(test);
}

bool operator==(const char * test, const text & obj)
{
    return obj.equals(test);
}

bool operator!=(const text & obj, const char * test)
{
    return !obj.equals(test);
}

bool operator!=(const char * test, const text & obj)
{ 
    return !obj.equals(test);
}

bool text::equals(const char * test) const
{
    if(!data || !test) return false;
    return !strcmp(test,data);
}

bool text::compare(const char * data, const char * test_text) const
{
    if(!test_text && !data) return false;
    if(!test_text) return true;
    if(!data) return false;
    return strcmp(data, test_text);
}

bool text::operator<(const text & obj) const
{
    return compare(data, obj.data);
}

bool text::operator>(const text & obj) const
{
    return compare(obj.data, data);
}

bool text::operator>=(const text & obj) const
{
    if( equals(obj.data) ) return true;
    return compare(data, obj.data);
}

bool text::operator<=(const text & obj) const
{
    if( equals(obj.data) ) return true;
    return compare(obj.data, data);
}

//OSTREAM incorporation is implemented here.
ostream& operator<<(ostream & out, const text & obj)
{
    if( obj.data )
        out << obj.data;
    if( obj.next )
        out << ", " << *obj.next;
    return out;
}

//Insertion operator for char*
text& operator<<(text & obj, const char * new_text)
{
    text new_text_class(new_text);
    return obj << new_text_class;
}

//Insertion operator
text& operator<<(text & obj, const text & new_text)
{
    if( !obj.data )
    {
        obj = new_text;
        return obj;
    }
    text * new_perm = new text(new_text);
    obj.insert(new_perm, obj.next);

    return obj;
}

//Recusively insert new keywords into this LLL.
bool text::insert(text * obj, text *& head)
{
    if(!head) 
    {
        head = obj;
        return true;
    }

    //If there's room here and the node has no next pointer, we may as well 
    //insert.
    if(!head -> data && !obj -> next && obj -> data)
    {
        *head = *obj;
        return true;
    }

    return insert(obj, head -> next);
}

//This is the assignmnet operator. It DOES make copies of the obj's next nodes.
text& text::operator=(const text & obj)
{
    if( data )
    {
        delete [] data;
        data = NULL;
    }

    if( obj.data )
    {
        data = new char[strlen(obj.data) + 1];
        strcpy(data, obj.data);
    }

    if( next )
    {
        delete next;
        next = NULL;
    }

    if( obj.next )
        next = new text(*obj.next);

    return *this;
}

//DEFAULT CONSTRUCTOR
text::text()
{
    data = NULL;
    next = NULL;
}

//CONSTRUCTOR
text::text(const char * new_text)
{
    data = new char[strlen(new_text) + 1];
    strcpy(data, new_text);
    
    next = NULL;
}

//COPY CONSTRUCTOR
text::text(const text & obj)
{
    data = new char[strlen(obj.data) + 1];
    strcpy(data, obj.data);

    if( obj.next )
        next = new text(*obj.next);
    else
        next = NULL;
}

//DESTRUCTOR
text::~text()
{
    if( data ) delete [] data;
    data = NULL;
    if( next )
        delete next;
    next = NULL;
}

