#include <stdlib.h>
#include <stdio.h>

typedef unsigned int uint;

/*
 * Make an unsigned int with one bit set, as indicated by the index
 */
uint make_one(uint index)
{
    int x = 0x1;
    return x << (index);
}

/*
 * Display which bits are on in the result using the mask
 */
void print_result(uint result)
{
    uint mask = 0x8000;
    int i;

    for (i=0; i<16; ++i)
    {
        uint val = mask & result;
        if (i>0 && i%4 == 0)
            printf(" ");

        if (0 == val)
            printf("0");
        else
            printf("1");

        mask >>= 1;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    /*
     * Capture errors and display them
     */
    char *endptr;
    int result=0;
    int i;

    /*
     * Only proceed if we have arguments
     */
    if (argc < 2)
    {
        printf("Usage: ./set_bits [index] [of] [bits]\n");
        exit(EXIT_FAILURE);
    }

    /*
     * Read in all the bits and make the result
     */
    for (i=1; i < argc; ++i)
    {
        uint val = strtoul(argv[i], &endptr, 10);

        /*
         * Catch case where there is no number found
         */
        if (endptr == argv[i])
        {
            printf("No numbers found\n");
            exit(EXIT_FAILURE);
        }

        /*
         * Catch case where a number is outside range
         */
        if (val > 15)
        {
            printf("Number outside of range: %u\n", val);
            exit(EXIT_FAILURE);
        }

        /*
         * Get the value of one indicies turned on, then OR that with our final
         * result
         */
        result |= make_one(val);
    }

    /*
     * Call print result function to display the results
     */
    print_result(result);
    printf("Decimal: %u\n",result);
    return 0;
}
