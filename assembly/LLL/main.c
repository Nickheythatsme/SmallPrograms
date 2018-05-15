#include "LLL.h"

int main(int argc, char *argv[])
{
    struct node *head = NULL;
    int i;
    int result=1;

    for (i=0; i < 1000; ++i)
    {
        insert(&head, rand() % 11);
    }
    i=0;
    while (result == 1)
    {
        result = remove_LLL(&head, 10);
        ++i;
    }
    printf("Removed %d 10's\n", i);

    return 0;
}
