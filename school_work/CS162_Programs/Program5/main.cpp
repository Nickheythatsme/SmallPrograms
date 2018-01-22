/*
 * Nicholas Grout
 * Prof: Karla Fant
 * Program 5
 */
#include "header.h"

//main function which calls all other functions
int main()
{
    int choice = 0;
    node * head = NULL;

    //do this loop until user indicates they wish to quit
    do{
        //calls menu function
        choice = MainMenu();
        switch(choice){
            case 1: 
                //call a function which reads in a step and sends it to
                //the node struct to be added.
                GetTempStep(head);
                break;
            case 2:
                //display all nodes
                head -> display(head,0);
                break;
            case 3:
                //if is for if the step doesn't exist.
                //If it doesn't exist, an error message
                //will be shown.
                if(!head -> display(head,WhichStep(),0))
                    cout << "Step not found...\n";
                break;
        }
    }while(choice);
    delete head;
    return 0;
}


//This function makes a local char[] variable 'temp' and reads in a single step
//from the user. This step is sent to the LLL, and the function ends, deleting
//the local variable 'temp'
void GetTempStep(node * & head)
{
    char temp[STEP];
    //the following line displays the step the user is entering.
    //For example: "1) "
    cout << head -> count(head) << ") ";
    cin.get(temp,STEP,'\n');
    cin.ignore(100,'\n');
    //call add function
    head -> add_at_end(head,temp);
    return;
}


//Main menu function which displays options and
//gets the menu choice from the user
int MainMenu()
{
    int choice = 0;
    cout << "\n\nEnter choice:\n"
         << "1) Add steps\n"
         << "2) Display all steps\n"
         << "3) Display one particular step\n"
         << "0) Quit\n"
         << "Choice: ";
    cin >> choice;
    cin.ignore(100,'\n');
    cout << endl << endl;
    return choice;
}


//used to get which steps the user wishes to input.
int WhichStep()
{
    int choice = 0;
    cout << "Which step would you like to see?";
    cin >> choice;
    cin.ignore(100,'\n');
    return (choice - 1);
}
