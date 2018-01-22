/*
 * Nicholas Grout
 * Prof: Karla Fant
 * Program 4
 *
 * Note: I spoke with Karla and she said that LLLs would be okay on this
 * assignment
 */
#include "header.h"

//copy a struct into a node
//used whenever a new job is added
void node::copy(jobs * a_job)
{
    data -> company = new char[strlen(a_job -> company)+1];
    strcpy(data -> company, a_job -> company);

    data -> title = new char[strlen(a_job -> title)+1];
    strcpy(data -> title, a_job -> title);

    data -> hours = new char[strlen(a_job -> hours)+1];
    strcpy(data -> hours, a_job -> hours);

    data -> finish = new char[strlen(a_job -> finish)+1];
    strcpy(data -> finish, a_job -> finish);

    data -> start = new char[strlen(a_job -> start)+1];
    strcpy(data -> start, a_job -> start);

    data -> comments = new char[strlen(a_job -> comments)+1];
    strcpy(data -> comments, a_job -> comments);
}

//compares a node company to the company name that was sent
//Used for the edit function
bool node::compare(char comp_name[])
{
    if(!data) return 0;
    if(!strcmp(data -> company,comp_name)) return 1;
    else return 0;
}

//displays all companies. Used for the edit function
void node::displayCompanies(node * head)
{
    if(!head) return;
    cout << head -> data -> company << endl;
    displayCompanies(head -> next);
}

//displays all job info
void node::display(node * head)
{
    if(!head) return;
    cout << "\nCompany:  "
         << head -> data -> company << '\n'
         << "Title:    "
         << head -> data -> title << '\n'
         << "Hours:    "
         << head -> data -> hours << '\n'
         << "Start:    "
         << head -> data -> start << '\n'
         << "Finish:   "
         << head -> data -> finish << '\n'
         << "Comments: "
         << head -> data -> comments << '\n';
    //for recursion
    display(head -> next);

    return;
}

//constructor
jobs::jobs()
{
    company = NULL;
    title = NULL;
    hours = NULL;
    finish = NULL;
    start = NULL;
    comments = NULL;
}

//destructor. This allows me to say
//delete jobs_variable;
//without any mem leaks 
jobs::~jobs()
{
    delete [] company;
    delete [] title;
    delete [] hours;
    delete [] finish;
    delete [] start;
    delete [] comments;

    company = NULL;
    title = NULL;
    hours = NULL;
    finish = NULL;
    start = NULL;
    comments = NULL;
}

//destructor
//this goes through each node recursively and deletes them.
node::~node()
{
    delete data;
    delete next;
}

