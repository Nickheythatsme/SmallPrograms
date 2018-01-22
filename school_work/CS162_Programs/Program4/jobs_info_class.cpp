/*
 * Nicholas Grout
 * Prof: Karla Fant
 * Program 4
 *
 * Note: I spoke with Karla and she said that LLLs would be okay on this
 * assignment
 */
#include "header.h"

//destructor
list::~list()
{
    delete head;
}

//constructor set head = NULL
list::list()
{
    head = NULL;
    job_count = 0;
}

//This is a private function which adds a struct to a node at the end of
//the LLL
void list::Add(node* & head,jobs * to_add)
{
    if(!head)
    {
        head = new node;
        head -> data = new jobs;
        //since head -> data = to_add;
        //just sends the address and doesn't work, we need a copy function
        //which individually copys each piece of information
        head -> copy(to_add);
        head -> next = NULL;
        //keep count of jobs
        ++job_count;
    }

    else
        //for recursion. So that the node may be added to the end of the list
        Add(head -> next, to_add);
}


//This is a public function used by main,
//becuase main doesn't have access to head
void list::Add(jobs * to_add)
{
    Add(head,to_add);
}

//This function reads in the individual information for a job/interview
//it is called to add new jobs, as well as to edit old jobs.
void list::ReadIn(jobs * a_job)
{
    char temp[200];
    int temp_int = 0;

    GetTempAnswer("Enter company name: ",temp);
    a_job -> company = new char[strlen(temp)+1];
    strcpy(a_job -> company,temp);

    GetTempAnswer("Enter job title: ",temp);
    a_job -> title = new char[strlen(temp)+1];
    strcpy(a_job -> title,temp);

    GetTempAnswer("Enter job hours: ", temp);
    a_job -> hours = new char[strlen(temp) +1 ];
    strcpy(a_job -> hours,temp);

    GetTempAnswer("Enter job start date: ",temp);
    a_job -> start = new char[strlen(temp)+1];
    strcpy(a_job -> start,temp);

    GetTempAnswer("Enter job end date:  ",temp);
    a_job -> finish = new char[strlen(temp)+1];
    strcpy(a_job -> finish,temp);

    GetTempAnswer("Enter job comments: ",temp);
    a_job -> comments = new char[strlen(temp)+1];
    strcpy(a_job -> comments,temp);

    return;
}

//called exclusively by the ReadJobInfo function
//to reduce lines and improve readability
void list::GetTempAnswer(char message[], char temp[])
{
    cout << message;
    cin.get(temp,200,'\n');
    cin.ignore(100,'\n');
    return;
}

//This recursive function displays all the company info
void list::DisplayAllCompanies(node * head)
{
    cout << "Companies: \n";
    head -> displayCompanies(head);
}

//this recursive function displays all LLL info
void list::DisplayAll()
{
    head -> display(head);
    return;
}

//this allows the user to choose, and edit a job
bool list::Edit()
{
    if(!head) return 0;
    //used for temporary storage
    char comp_name[NAME];
    jobs *a_job = new jobs;

    //calls DisplayAllCompanies function
    DisplayAllCompanies(head);
    //Calls this function to get the answer
    GetTempAnswer("Enter company name to edit: ",comp_name);

    //for traversal
    node * current = head;
    //comparing each company name in the LLL to the one submitted by the user
    while(current -> next && !(current -> compare(comp_name)))
        current = current -> next;
    if(!(current -> compare(comp_name)))
    {
        cout << "Company not found...";
        return 0;
    }

    cout << "Editing: " 
         << current -> data -> company << endl;
    if(GetAnswer("Correct? (Y or N): ") != 'Y')
        return 0;

    //get job info
    ReadIn(a_job);
    //delete the old
    delete current -> data;
    current -> data = new jobs;
    //copy in the new job to the old 
    current -> copy(a_job);
    delete a_job;

    return 1;
}

//Get a temporary answer from a user for "Y or N"
char list::GetAnswer(char message[])
{
    char answer = ' ';
    cout << message;
    cin >> answer;
    cin.ignore(100,'\n');

    return toupper(answer);
}

//Loads in jobs/interviews from a file
int list::Load(char file_name[])
{
    char temp[TEMP];
    int temp_int = 0;
    jobs * a_job = new jobs;
    fstream file_in;
    file_in.open(file_name);

    if(!file_in) return 0;

    //"prime the pump"
    file_in.get(temp,TEMP,DELIM);
    file_in.ignore(100,DELIM);
    a_job -> company = new char[strlen(temp)+1];
    strcpy(a_job -> company,temp);

    for(int i = 0; i < 200 && file_in && !file_in.eof(); ++i)
    {

        file_in.get(temp,TEMP,DELIM);
        file_in.ignore(100,DELIM);
        a_job -> title = new char[strlen(temp)+1];
        strcpy(a_job -> title,temp);

        file_in.get(temp,TEMP,DELIM);
        file_in.ignore(100,DELIM);
        a_job -> hours = new char[strlen(temp) +1 ];
        strcpy(a_job -> hours,temp);

        file_in.get(temp,TEMP,DELIM);
        file_in.ignore(100,DELIM);
        a_job -> start = new char[strlen(temp)+1];
        strcpy(a_job -> start,temp);

        file_in.get(temp,TEMP,DELIM);
        file_in.ignore(100,DELIM);
        a_job -> finish = new char[strlen(temp)+1];
        strcpy(a_job -> finish,temp);

        file_in.get(temp,TEMP,'\n');
        file_in.ignore(100,'\n');
        a_job -> comments = new char[strlen(temp)+1];
        strcpy(a_job -> comments,temp);

        //adding the job to the end of the node.
        Add(head,a_job);
        //watch out for memory leaks
        delete a_job;
        a_job = new jobs;

        //This is so a blank job isn't created a the end of the LLL
        file_in.get(temp,TEMP,DELIM);
        file_in.ignore(100,DELIM);
        a_job -> company = new char[strlen(temp)+1];
        strcpy(a_job -> company,temp);
    }

    //watch out for memory leaks
    delete a_job;
    //for the main, to show how many jobs were loaded
    return job_count;
}

//Writes jobs/interviews to a file
//This is not recursive because it's called by main.
//I just learned more about recursion and 
//I don't want to redo it the day the program is due
bool list::Write(char file_name[])
{
    ofstream file_out;
    file_out.open(file_name,ios::app);
    if(!file_out || !head) return 0;

    //used for traversal
    node * current = head;
    while(file_out && current)
    {
        file_out << current -> data -> company << DELIM
                 << current -> data -> title << DELIM
                 << current -> data -> hours << DELIM
                 << current -> data -> start << DELIM
                 << current -> data -> finish << DELIM
                 << current -> data -> comments << '\n';
        current = current -> next;
    }

    file_out.close();
    file_out.clear();
    return (!current);
}
