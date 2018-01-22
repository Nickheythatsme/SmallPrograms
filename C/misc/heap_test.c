#include <stdio.h>
#include <stdlib.h>

#define ALLOC_S 1024

int main(int argc, char *argv[])
{
    unsigned long bytes = 0;
    char *array;

    bytes += sizeof(char) * ALLOC_S;
    array = (char*) malloc(bytes);
    do{
        printf("Bytes: %lu\n",bytes);
        free(array);
        bytes += sizeof(char) * ALLOC_S;
        array = (char*) malloc(bytes);
    }while(array);

    return 0;
}
