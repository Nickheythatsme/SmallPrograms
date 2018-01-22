//Nicholas Grout
//Professor Fant
//Program 3
#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

//using constants for the different struct array sizes,
//as well as for the delimeter
const int NAME = 61;
const int TITLE = 61;
const int COMMENTS = 1001;
const int DATE = 11;
const char DELIM = '|';


//main struct that is used for jobs and interviews and temp
struct job_info
{
    char company[NAME];
    char title[TITLE];
    int hours;
    char start[DATE];
    char finish[DATE];
    char comments[COMMENTS];
};

//function declarations. Functions defined in more detail in main.cpp
void ClearScreen(int lines);
void ClearScreen(int lines, char message[], int after_lines);
bool ReadIn(char file_name[], job_info job[]);
void Write(char file_name[], job_info & job);
bool MainMenu(job_info interviews[], job_info jobs[]);
void EnterNew(char job_file_name[], char interviews_file_name[]);
void MoveInterview(job_info interviews[], char job_file[]);
void Display(job_info job[]);
bool Quit();

