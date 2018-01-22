#include <stdlib.h>
#include <stdio.h>

long fibonacci(long n);

int main(int argc, char *argv[])
{
    long n;
    sscanf(argv[1],"%ld",&n);
    printf("%ld\n",fibonacci(n));

    return 0;
}
