#include <stdio.h>

unsigned long hash(char *data, long len)
{
    unsigned hvalue = 0;
    unsigned tmp = 0;
    long i = 0;

    for(; i < len - 4; i += 4)
    {
        tmp += data[i];
        tmp += data[i+1];
        tmp += data[i+2];
        tmp += data[i+3];
        hvalue <<= 16;
        hvalue ^= tmp;
    }

    for(; i < len; i++)
    {
        tmp += data[i];
    }
    hvalue <<= 16;
    hvalue ^= tmp;

    hvalue ^= hvalue << 3;
    hvalue += hvalue >> 5;
    hvalue ^= hvalue << 4;
    hvalue += hvalue >> 17;
    hvalue ^= hvalue << 25;


    return hvalue;
}
