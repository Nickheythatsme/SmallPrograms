/*
 * Nicholas Grout
 * Prof: Karla Fant
 * Program 4
 *
 * Note: I spoke with Karla and she said that LLLs would be okay on this
 * assignment
 */

#include "header.h"


int main()
{
    list interviews; //for interviews
    list jobs_list; //for jobs
    int choice = 0; //indicates user's choice from the menu
    jobs * temp_job = new jobs; //temporarily store job info

    ClearScreen(100);
    WelcomeMessage();

    //reading jobs in
    cout << "Read " << jobs_list.Load("jobs.txt")
         << " jobs from jobs.txt.\n";

    //reading interivews in
    cout << "Read " << interviews.Load("interviews.txt")
         << " interviews from interviews.txt.\n";

    do{
        //Prompts the user with the main menu options
        choice = MainMenu();
        ClearScreen(100);
        switch(choice)
        {
            case 1: 
                //Call ReadIn function
                //In heinsight I think this would have made more sense as
                //a local function
                jobs_list.ReadIn(temp_job);
                //add the temp job
                jobs_list.Add(temp_job);
                delete temp_job;
                temp_job = new jobs;
                break;
            case 2:
                //same for interviews
                interviews.ReadIn(temp_job);
                interviews.Add(temp_job);
                delete temp_job;
                temp_job = new jobs;
                break;
            case 3:
                //display all jobs
                jobs_list.DisplayAll();
                break;
            case 4:
                //display all interviews
                interviews.DisplayAll();
                break;
            case 5:
                //Edit jobs
                jobs_list.Edit();
                break;
            case 6:
                //Edit interivews
                interviews.Edit();
                break;
        }
    }while(choice);
    //writing out jobs/interviews. There is an error
    //message if LLL is empty, or if something goes wrong
    if(!interviews.Write("interviews.txt"))
        cout << "Error writing interviews\n";
    if(!jobs_list.Write("jobs.txt"))
        cout << "Error writing jobs\n";

    delete temp_job;
    return 0;
}

//just displays the options and allows user to indicate which one they want
int MainMenu()
{
    int choice = 0;
    cout << "\nEnter choice: \n"
         << "1 - Add Job \n"
         << "2 - Add Interview \n"
         << "3 - Display Jobs \n"
         << "4 - Display Interivews \n"
         << "5 - Edit Job \n"
         << "6 - Edit Interivew \n"
         << "0 - Save and quit \n";
    cin >> choice;
    cin.ignore(100,'\n');
    return choice;
}

//useful for adding blank screens
void ClearScreen(int lines)
{
    for(int i = 0; i < lines; ++i)
        cout << endl;
    return;
}

//simple welcome message
void WelcomeMessage()
{
    cout << "Welcome to the job tracking program.\n"
         << "You can display jobs, edit jobs, or add new jobs.\n"
         << "You can also do the same for interviews.\n"
         << "Press 0 at the menu to save and quit.\n\n";
    return;
}
