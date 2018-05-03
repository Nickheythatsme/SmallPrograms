#include "track_file.h"

/*
 * Read in a file, return the length of the file
 */
char* simple_read(const char *fname)
{
    FILE *in = fopen(fname, "r");
    size_t len=0;
    char *buff;

    if (!in) 
    {
        printf("Cannot read file: %s", fname);
        return 0;
    }
    // Find file length
    do{
        fgetc(in);
        len++;
    } while ( !feof(in) );

    fclose(in);
    fopen(fname, "r");

    buff = (char*) malloc(sizeof(char) * len);
    // size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
    fread(buff, sizeof(char), len, in);

    fclose(in);
    return buff;
}

/*
 * Handle the read file function, create a new file struct and store it
 */
//TODO
size_t add(struct bfile *new_file, struct bfile **head)
{
    if (!*head)
    {
        *head = new_file;
        return 1;
    }
    return add(new_file, &(*head)->next) + 1;
}

/*
 * Compare two files to see if they're the same
 */
// TODO
size_t compare(const char *fname1, const char *fname2)
{
    return 0;
}

/* 
 * Display all files in LLL
 */
void display_bfile(struct bfile *head)
{
    if (!head) return;
    printf("Filename: %s\nTime: %s\n", head->name, ctime(&head->time_read));
    return display_bfile(head->next);
}
