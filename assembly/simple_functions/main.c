#include <stdlib.h>
#include <stdio.h>

#define ITERATIONS 10000
#define ARRAY_SIZE 10

/* 
 * Assembly Functions 
 */
/* Zero all values in an array */
void zero_array(int *array, size_t len);
/* Reverse the order of an array */
void reverse(int *array, size_t len);
/* Copy an array. Return new array */
int* copy(int *src, size_t len);

/*
 * Non assembly functions 
 */
void display_sizes(); 
void display_array(int *array, unsigned long len);

int main(int argc, char *argv[])
{
    unsigned long i;
    /* Make the array */
    int *array = (int*)malloc(sizeof(int) * ARRAY_SIZE);
    int *dest;
    for  (i=0; i<ARRAY_SIZE; ++i)
    {
        array[i] = i;
    }

    /* Call assembly functions */
    dest = copy(array, ARRAY_SIZE);
    printf("Address of dest: 0x%x\n", dest);
    display_array(dest, ARRAY_SIZE);
    free(array);

    /*
    zero_array(array, ARRAY_SIZE);
    display_array(array, ARRAY_SIZE);
    */

    return 0;
}

/* Display the contents of the array */
void display_array(int *array, unsigned long len)
{
    int i;
    for (i=0; i < len; ++i)
        printf("%d, ", array[i]);
    printf("\n");

}

/* Display the number of bytes each data type is */
void display_sizes()
{
    printf("sizeof(char)\t%lu\n", sizeof(char));
    printf("sizeof(short)\t%lu\n", sizeof(short));
    printf("sizeof(int)\t%lu\n", sizeof(int));
    printf("sizeof(int*)\t%lu\n", sizeof(int*));
    printf("sizeof(float)\t%lu\n", sizeof(float));
    printf("sizeof(long)\t%lu\n", sizeof(long));
    printf("sizeof(double)\t%lu\n", sizeof(double));
    printf("sizeof(long double)\t%lu\n", sizeof(long double));
}
