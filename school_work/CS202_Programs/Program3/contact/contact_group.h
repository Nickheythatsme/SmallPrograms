/*
 * Nicholas Grout
 * Program 3
 */
#include "contact.h"
#include <fstream>

#ifndef CONTACT_GROUP_
#define CONTACT_GROUP_

class contact_node : public contact
{
    public:
        contact_node(const char * name, const char * phone_num);
        contact_node();
        contact_node(const contact_node & obj);
        contact_node(const contact & obj);
        ~contact_node();
        //Insert at the end of the DLL
        bool insert(const contact_node & obj);
        bool insert(const contact_node & obj,contact_node *& root);
        //Insert immediately to the next node. Shift any nodes already there.
        bool insert_next(const contact_node & obj);
        contact_node* next_node(void) const;
        contact_node& operator=(const contact_node & obj);
        friend ostream& operator<<(ostream & out, const contact_node & obj);
        friend contact_node& operator<<(contact_node & obj, 
                const contact_node & new_contact);
        friend contact_node& operator<<(contact_node & obj, 
                const contact & new_contact);
        bool display_all(ostream & out) const;
        bool connect_next(contact_node * new_next);
    protected:
        ostream& display(ostream & out) const;
    private:
        contact_node * next;
};

class contact_group
{
    public:
        contact_group();
        contact_group(const contact_group & obj);
        ~contact_group();
        friend ostream& operator<<(ostream & out, const contact_group & obj);
        friend contact_group& operator<<(contact_group & obj, 
                const contact & new_contact);
        friend contact& operator>>(contact_group & obj,
                contact & new_contact);
        contact_group& operator = (const contact_group & obj);
        contact& operator[](const char * text) const;
    protected:
        ostream& display(ostream & out) const;
        bool remove_head(contact & to_return);
        ifstream& read_in(ifstream & in, text & text_obj);
        ifstream& read_in(ifstream & in, text & text_obj, char delim);
    private:
        contact* find(const char * name, contact_node * head) const;
        void remove_all(contact_node * head);
        contact_node * head;
};

#endif
