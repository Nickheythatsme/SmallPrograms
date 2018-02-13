#include <stdio.h>

#define CORRECT 1

int stack(long v);

int main(int argc, char **argv)
{
    if(stack(10) == CORRECT)
        printf("Correct!\n");
    else
        printf("Incorrect\n");
    return 0;
}
