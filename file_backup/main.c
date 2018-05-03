#include "track_file.h"

int main(int argc, char **argv)
{
    char *fcontents = simple_read("main.c");
    printf("File contents: \n%s", fcontents);

    struct bfile *head = NULL;
    for (int i=0; i < 10; ++i)
    {
        // Make the new b_file object
        struct bfile *new_file = (struct bfile*) malloc(sizeof(struct bfile) * 1);
        new_file->next=NULL;
        new_file->contents = fcontents;
        new_file->time_read = time(NULL);
        new_file->name = (char*) malloc(sizeof(char) * strlen("main.c"));
        strcpy(new_file->name, "main.c");

        // Add it to the LLL
        // size_t add(struct bfile *new_file, struct bfile **head)
        add(new_file, &head);
        printf("Added file: %s\n", new_file->name);
    }
    display_bfile(head);
}
