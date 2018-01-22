#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/time.h>

/* #define TRIALS 100000000L */
#define TRIALS 1L

unsigned long hash(char *data, long len);

int main(int argc, char *argv[])
{
    long iter=0;
    struct timeval tf, ti;
    unsigned long timems=0;
    unsigned long len;
    unsigned long hvalue;

    if( argc != 2 )
    {
        printf("Usage: ./hash [word]\n");
        exit(EXIT_FAILURE);
    }

    /* Get argument length */
    len = strlen(argv[1]);

    /* Start trials */
    gettimeofday(&ti, NULL);
    for (iter = 0; iter < TRIALS; iter++)
    {
        hvalue = hash(argv[1],len);
    }

    /* End trials */
    gettimeofday(&tf, NULL);

    /* Calculate and format time */
    printf("%lu\n",hvalue);
    timems=(tf.tv_sec*1000+tf.tv_usec/1000) - (ti.tv_sec*1000+tf.tv_usec/1000);
    printf("Iterations: %lu, TotalTime : %lu ms, IterTime : %f us\n", iter, timems, (1000.0*timems)/TRIALS);

    exit(EXIT_SUCCESS);
}
