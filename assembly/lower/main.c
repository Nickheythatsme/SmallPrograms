#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#define TRIALS 100000000L

void lower(char *s);

int main(int argc, char *argv[])
{
    long iter=0;
    struct timeval tf, ti;
    unsigned long timems=0;
    char buffer[1024];

    scanf("%s",buffer);

    /* Start trials */
    gettimeofday(&ti, NULL);
    for (iter = 0; iter < TRIALS; iter++)
    {
        lower(buffer);
    }
    /* End trials */
    gettimeofday(&tf, NULL);

    timems=(tf.tv_sec*1000+tf.tv_usec/1000) - (ti.tv_sec*1000+tf.tv_usec/1000);
    printf("%s\n", buffer);
    printf("Iterations: %lu, TotalTime : %lu ms, IterTime : %f us\n", iter, timems, (1000.0*timems)/TRIALS);

    exit(EXIT_SUCCESS);
}
