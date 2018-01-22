/*
 * Nicholas Grout
 * Prof: Karla Fant
 * Program 5
 */
#include "header.h"

//Adds one to the end of the list
void node::add_at_end(node * & head, char to_add[])
{
    if(!head)
    {
        head = new node;
        //make dynamically allocated array
        head -> data = new char[strlen(to_add) + 1];
        //copy step into the new node's data
        strcpy(head->data,to_add);
        head -> next = NULL;
    }
    else
        add_at_end(head -> next, to_add);
}

//recursively displays all nodes in LLL
void node::display(node * head,int current)
{
    if(!head) return;
    cout << current + 1 << ") "
         <<head -> data << endl;
    display(head -> next, ++current);
    return;
}

//This functin displays one particular step. The step that matches choice
//if that step does not exist, this function returns a 0
bool node::display(node * head, int choice, int current)
{
    if(!head) return 0;
    if(current == choice)
    {
        cout << choice + 1 << ") " << head -> data << endl;
        return 1;
    }
    else
        display(head -> next,choice,++current);
}

//simply counts the number of nodes in LLL.
//Used to make step entry more friendly
int node::count(node * head)
{
    if(!head) return 1;
    return count(head -> next) + 1;
}

//node constructor
node::node()
{
    data = NULL;
}

//destructor
//this goes through each node recursively and deletes them.
node::~node()
{
    delete [] data;
    delete next;
}

