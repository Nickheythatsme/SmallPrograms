#include <stdlib.h>
#include <stdio.h>

long fact(long n);

int main(int argc, char *argv[])
{
    long n;
    sscanf(argv[1],"%ld",&n);
    printf("%ld\n",fact(n));

    return 0;
}
