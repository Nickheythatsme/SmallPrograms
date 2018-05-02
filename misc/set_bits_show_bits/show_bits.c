#include <stdlib.h>
#include <stdio.h>

typedef unsigned int uint;

/*
 * RETURN an array of 16 uints, turned on or off
 */
uint* find_index(uint val)
{
    uint *bits;
    uint mask = 0x8000;
    uint i;

    /*
     * Allocate the bit array
     */
    bits = (uint*) malloc(sizeof(uint) * 16);

    /*
     * Loop through and test which bits are on
     */
    for (i=0; i<16; ++i)
    {
        bits[i] = ((mask & val) != 0);
        mask >>= 1;
    }
    return bits;
}

int main(int argc, char **argv)
{
    uint val;
    char *endptr;
    uint i;
    uint *bits;

    /*
     * Only proceed if we have arguments
     */
    if (argc != 2)
    {
        printf("Usage: ./show_bits [value]\n");
        exit(EXIT_FAILURE);
    }

    /*
     * Store the value
     */
    val = strtoul(argv[1], &endptr, 10);

    /*
     * Catch case where there is no number found
     */
    if (endptr == argv[1])
    {
        printf("No numbers found\n");
        exit(EXIT_FAILURE);
    }

    /*
     * Catch case where a number is outside range
     */
    if (val > 0x8000)
    {
        printf("Number outside of range: %u\n", val);
        exit(EXIT_FAILURE);
    }

    /* 
     * Call find_index function
     */
    bits = find_index(val);

    /*
     * Print the values from the bits
     */
    for (i=0; i<16; ++i)
    {
        if (i !=0 && i%4 ==0)
            printf(" ");
        printf("%d", bits[i]);
    }
    printf("\n");


    return 0;
}

