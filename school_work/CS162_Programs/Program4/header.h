/*
 * Nicholas Grout
 * Prof: Karla Fant
 * Program 4
 *
 * Note: I spoke with Karla and she said that LLLs would be okay on this
 * assignment
 */

#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;
const int NAME = 51;
const int TEMP = 200;
const char DELIM = '|';

//used to store all job information
struct jobs
{
    jobs();
    char *company;
    char *title;
    char *hours;
    char *finish;
    char *start;
    char *comments;
    ~jobs();
};

//used to handle the LLL
struct node
{
    jobs * data;
    node * next;
    //copys a job struct to a new node
    void copy(jobs *);
    //displays all job info recursively
    void display(node * head);
    //displays all company infor recursively
    void displayCompanies(node * head);
    //compares a company name with the company name in the node
    bool compare(char comp_name[]);
    ~node();
};

//main list class for handingly/storing jobs/interviews
class list
{
    public:
        //constructor
        list();
        //adds a struct to a new node in LLL
        void Add(jobs * to_add);
        //Displays all job info
        void DisplayAll();
        //Displays all company names in LLL
        void DisplayAllCompanies(node * head);
        //Read in new job information
        void ReadIn(jobs * a_job);
        //Used for the ReadIn function to reduce lines
        void GetTempAnswer(char message[],char temp[]);
        //easily get a Y or N for a function
        char GetAnswer(char message[]);
        //Allows user to choose and edit a job/interview
        bool Edit();
        //loads in jobs/interviews
        int Load(char file_name[]);
        //Write all of the LLL to a file
        bool Write(char file_name[]);
        //deconstructor
        ~list();

    private:
        //the main() function does not have access to head. So I made another
        //private function which does the actual work. The public Add() just
        //calls this function
        void Add(node * & head,jobs * to_add);
        //for LLL
        node * head;
        //track how many jobs
        int job_count;
};

//prototypes
int MainMenu();
void ClearScreen(int lines);
void WelcomeMessage();
