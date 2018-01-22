#include <stdio.h>
#include <stdlib.h>


int fib(int n, unsigned long *frames);

int main(int argc, char *argv[])
{
    unsigned long *frames = (unsigned long*) malloc(sizeof(unsigned long) * 1);
    int n;
    frames[0] = 0;

    sscanf("%d",argv[1],n);
    fib(n, frames);

    free(frames);
    return 0;
}

int fib(int n, unsigned long *frames)
{
    *frames += 1;
    if( *frames % 1000 == 0 )
        printf("Frame: %lu\n",*frames);

    if(n == 1)
        return 1;
    if(n == 0)
        return 0;
    return fib(n-1, frames) + fib(n-2, frames);
}
