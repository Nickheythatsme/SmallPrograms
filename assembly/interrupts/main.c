#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

/*
#define TRIALS 100000000L
*/
#define TRIALS 1L

void interrupts(const char *word);

int main(int argc, char *argv[])
{
    long iter=0;
    struct timeval tf, ti;
    unsigned long timems=0;

    if( argc != 2 )
    {
        printf("Usage: ./a.out [word]\n");
        exit(EXIT_FAILURE);
    }

    /* Start trials */
    gettimeofday(&ti, NULL);
    for (iter = 0; iter < TRIALS; iter++)
    {
        interrupts(argv[1]);
    }
    /* End trials */
    gettimeofday(&tf, NULL);

    timems=(tf.tv_sec*1000+tf.tv_usec/1000) - (ti.tv_sec*1000+tf.tv_usec/1000);
    printf("Iterations: %lu, TotalTime : %lu ms, IterTime : %f us\n", iter, timems, (1000.0*timems)/TRIALS);

    exit(EXIT_SUCCESS);
}
