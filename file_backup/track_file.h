#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


struct bfile
{
    char *name;
    char *contents;
    time_t time_read;
    struct bfile *next;
};

/*
 * Read in a file, return the length of the file
 */
char* simple_read(const char *fname);

/*
 * Handle the read file function, create a new file struct and store it
 */
size_t add(struct bfile *new_file, struct bfile **head);

/*
 * Compare two files to see if they're the same
 */
size_t compare(const char *fname1, const char *fname2);

/* 
 * Display all files in LLL
 */
void display_bfile(struct bfile *head);
