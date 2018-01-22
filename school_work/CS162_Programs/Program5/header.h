/*
 * Nicholas Grout
 * Prof: Karla Fant
 * Program 5
 */

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
//global constant for the step size
const int STEP = 200;

//for the nodes in the LLL. I put most of the work in the node struct
//to keep it relatively simple. The main functions handle the user interaction,
//and the nodes handle displaying and managing data.
struct node
{
    node();
    node * next;
    char * data;
    void add_at_end(node* & head, char to_add[]);
    void display(node * head,int current);
    bool display(node * head, int choice, int current);
    int count(node * head);
    ~node();
};
//function prototypes
void GetTempStep(node * & head);
int MainMenu();
int WhichStep();
