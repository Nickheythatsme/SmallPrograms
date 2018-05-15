#include <stdlib.h>
#include <stdio.h>

/* Zero all values in an array */
void zero_array(int *array, size_t len)
{
    int i;
    for (i=0; i<len; ++i)
    {
        array[i] = 0;
    }
}

/* Reverse the contents of an array */
void reverse(int *array, size_t len)
{
    int temp;
    int i;

    for (i=0; i < len/2; ++i)
    {
        temp = array[i];
        array[i] = array[len-1-i];
        array[len-1-i] = temp;
    }
}


/* Copy an array. Return new array */
int* copy(int *src, size_t len)
{
    int *dest = (int*) malloc(sizeof(int) * len);
    int i;
    for (i=0; i<len; ++i)
    {
        dest[i] = src[i];
    }
    return dest;
}
