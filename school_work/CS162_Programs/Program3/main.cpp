//Nicholas Grout
//Professor Fant
//Program 3

#include "Program3.h"

/* This program tracks potential jobs before and after interveiws.
 * The user can choose to see jobs they have either interviewed for already,
 * or jobs they plan to interview for.
 * The user can also add new jobs, move jobs from the before interview file
 * to the after interview file. Each job entry contains the company name, the
 * title of the position, the number of hours, the start date and finish date,
 * and any finishing comments.
 */

int main()
{
    job_info jobs[20]; //Create 20 entries for jobs and interviews
    job_info interviews[20]; //these hold the jobs and interviews after
                             //they are read.

    ClearScreen(100); //Clear screen easily with a clear screen function

    //this is a do/while loop because it repeats as long as the user indicates
    //that they do not wish to quit. The ReadIn functions are in here as a
    //bonus, so that everytime a new job is entered, the structs will be
    //updated.
    do{
        //BTW g++ compiler hates func("string") I guess it's a conversion from a
        //str constant to a char pointer. That's why you get like 8 error
        //messages when you compile.
        ReadIn("jobs.txt",jobs); //calls read function which reads from file
        ReadIn("interviews.txt",interviews);
    }while(MainMenu(interviews,jobs)); //calls main menu


    //most of the work is done outside of main(). This is to keep main more or
    //less the initiator of everything. I could have put the switch statement
    //in main. But it seems fine in MainMenu(). If I needed to expand this
    //program however I would probably need to put the switch statment back
    //into main, making main() a data manager rather than function initiallizer.

    return 0;
}

//Returns a bool value based on if the user wishes to quit.
//Also calls other functions depending on the user choice.
bool MainMenu(job_info interviews[], job_info jobs[])
{
    int choice = 0;

    do{
    ClearScreen(100); 

    //menu options
    cout << "Enter your choice below:\n"
         << "1) Display Jobs\n"
         << "2) Display Interviews\n"
         << "3) Create new job or interview\n"
         << "4) Move interview\n"
         << "5) Quit\n"
         << "Choice: ";
    cin >> choice;
    //repeat while not a valid choice.
    }while(choice <= 0 || choice > 5);

    //using a switch statement which depends on the number the user entered.
    switch(choice)
    {
        case 1:
            ClearScreen(100,"   ***Jobs***",0);
            Display(jobs);
            break;
        case 2:
            ClearScreen(2,"     ***Interviews***",0);
            Display(interviews);
            break;
        case 3:
            EnterNew("jobs.txt","interviews.txt");
            break;
        case 4:
            MoveInterview(interviews,"jobs.txt");
            break;
        case 5:
            //calls Quit function which just asks if that's what they
            //really want to do. I could have added it to this function but
            //it keeps the MainMenu function simple when all it does is take
            //in choices and call other functions.
            if(!Quit())
                return 0;
            break;
    }
    return 1;
}


//Reads in job entries from the file that it is given. The job entries
//are read into the structure that is also sent to it.
//
//struct & name only passes one struct.
//struct name[] passes multiple structs under the name 'name'
bool ReadIn(char file_name[], job_info job[])
{
    fstream file_in;
    file_in.open(file_name);
    
    //repeats for 20 entries, and as long as the file is successfully read,
    //and as long as it's not the end of the file.
    for(int i = 0; i < 20 && file_in && !file_in.eof(); ++i)
    {
        file_in.get(job[i].company,NAME,DELIM);
        file_in.ignore(100,DELIM);
        file_in.get(job[i].title,TITLE,DELIM);
        file_in.ignore(100,DELIM);
        file_in >> job[i].hours;
        file_in.ignore(100,DELIM);
        file_in.get(job[i].start,DATE,DELIM);
        file_in.ignore(100,DELIM);
        file_in.get(job[i].finish,DATE,DELIM);
        file_in.ignore(100,DELIM);
        file_in.get(job[i].comments,COMMENTS,'\n');
        file_in.ignore(100,'\n');

    }
    file_in.close();

    //return end of file function.
    //I don't use the bool value return, however there were previous builds
    //that used it. I decided to leave it as bool value because it doesn't
    //hurt anything, and if I wanted to add an error message in main() I could
    //easily do that.
    return file_in.eof();
}


//Simply adds new lines equal to the number sent to this funciton.
void ClearScreen(int lines)
{
    for(int i = 0; i < lines; ++i )
        cout << endl;
    return;
}


//adds new lines, then displays a message, then adds more lines if needed.
void ClearScreen(int lines, char message[], int after_lines)
{
    ClearScreen(lines);
    cout << message;
    ClearScreen(after_lines);
}


//Decided to pass the array structure instead of individual structures.
//This function displays any job_info struct sent to it in a readable format
void Display(job_info job[])
{
    //continue as long as there are jobs.
    //Using strlen(...) > 1 might have been cheap but it works.
    for(int i = 0; i < 20 && strlen(job[i].company) > 1; ++i)
    {
        cout << "\nJob/interview number: " << i + 1 << endl;
        cout << "Company: " << job[i].company << endl
             << "Title:   " << job[i].title << endl
             << "Hours:   " << job[i].hours << endl
             << "Start:   " << job[i].start << endl
             << "Finish:  " << job[i].finish << endl
             << "comments:" << job[i].comments << endl;
    }

    //the display jobs funciton would complete, then go back to mainmenu().
    //This meant that 100 new lines were added immediately after the job info
    //had been displayed. To stop this, I use cin.ignore() to stop the screen
    //until the user presses enter.
    cin.ignore(100,'\n');
    cout << "\nPress enter to continue...";
    cin.ignore(100,'\n');
    return;
}


//This function reads in all the data needed for a new job entry. At the end of
//this function it asks the user if it's an interview or a job, then it sends a
//temp struct of all the info to the write function. I decided to just have one
//temporary structure which is always being sent to the write function after
//every entry. This means that more than 20 jobs can be added at a time.
void EnterNew(char job_file[],char interview_file[])
{
    char answer = ' ';
    char type = ' ';
    job_info temp; //used to temporarily store user's job info.

    ClearScreen(100,"Enter new jobs or interviews",1);
    //this first do while loop continues while the user still has jobs to enter
    do{
        //the second do/while continues while response is invalid.
        do{
        cout << "Is this a job or interview (J or I): ";
        cin>>type;
        cin.ignore(100,'\n');
        }while(toupper(type) != 'J' && toupper(type) != 'I');

        //I realize this function is more than 30 statements. However I thought
        //it would be okay as most of the statements are doing relatively
        //similar functions, and there really isn't any way that we know to
        //reduce this.
        cout << "Company Name: ";
        cin.get(temp.company,NAME,'\n');
        cin.ignore(100,'\n');

        cout << "Position title: ";
        cin.get(temp.title,TITLE,'\n');
        cin.ignore(100,'\n');

        cout << "Hours (ex: 8): ";
        cin>>temp.hours;
        cin.ignore(100,'\n');

        cout << "Start date (DD/MM/YYYY): ";
        cin.get(temp.start,DATE,'\n');
        cin.ignore(100,'\n');

        cout << "Finish Date (DD/MM/YYYY): ";
        cin.get(temp.finish,DATE,'\n');
        cin.ignore(100,'\n');

        cout << "Comments: ";
        cin.get(temp.comments,COMMENTS,'\n');
        cin.ignore(100,'\n');

        //this calls the Write() function. Either for jobs.txt, adding it to
        //the jobs file, or interviews.txt, which would add it to the 
        //interview.txt file.
        if(toupper(type) == 'J')
            //I don't know how to make const arrays. Otherwise job_file would
            //not need to be passed everytime to every function that needs it.
            Write(job_file,temp); 
        else
            Write(interview_file,temp);

        //ask if more entries
        ClearScreen(2);
        cout << "More entries? (Y or N): ";
        cin >> answer;
        cin.ignore(100,'\n');

    }while(toupper(answer) == 'Y');

    return;
}


//This is the write function. It takes in one file name, and one struct.
//It opens the file, then writes each piece of data into it.
//Each data point is seperated by the delimeter '|'
//Each job is seperated by a new line.
void Write(char file_name[], job_info & job)
{
    ofstream out_file;
    //make sure to use ios::app to ensure the data is appended, rather than
    //written over other data.
    out_file.open(file_name, ios::app);
    if(out_file)
    {
        out_file << job.company << DELIM
                 << job.title   << DELIM
                 << job.hours   << DELIM
                 << job.start   << DELIM
                 << job.finish  << DELIM
                 << job.comments<< "\n";
    }
    out_file.close();
    out_file.clear();
    return;
}


//function used to ask user if they want to quit.
//Returns a 0 if yes. a 1 if no. It makes more sense when you look at 
//the loops in MainMenu() and main().
bool Quit()
{
    char answer = ' ';

    ClearScreen(100,"Are you sure you want to quit? (Y or N):",0);
    cin >> answer;
    cin.ignore(100,'\n');
    if(toupper(answer) == 'Y')
        return 0;
    else
        return 1;
}


//used to move a job in the interviews file to the jobs file.
void MoveInterview(job_info interviews[], char file_name[])
{
    int entry_num = 0;
    Display(interviews);
    cout << "\nSelect the job number for which you interviewed: ";
    cin >> entry_num;
    cin.ignore(100,'\n');

    Write(file_name, interviews[entry_num-1]);
    return;
}
