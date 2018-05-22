#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * UTF-8 encoding:
 *  0x00 - 0x7f is regular 1 byte ASCII character
 *  0x80 - 0xBF means this is a continuing byte for a multi-byte character
 *  0xC2 - 0xDF is the beginning byte of a two byte character
 *  0xE0 - 0xEF is the beginning byte of a three byte character
 *  0xF0 - 0xFF is the beginning byte of a four byte sequence
 *
 *  len      1st byte
 *  1 bytes  0xxxxxxx
 *  2 bytes  110xxxxx
 *  3 bytes  1110xxxx
 *  4 bytes  11110xxx
 */

/* UTF8 functions */
unsigned char char_len(char c);

/* Testing functions */
int test_len();

int main(int argc, char *argv[])
{
    char clen = 0;
    int slen = 0;
    int i = 0;

    if (argc != 2)
    {
        printf("Usage: ./utf8 [utf8 charater string]\n");
        exit(EXIT_FAILURE);
    }

    /* 
     * Test and display the length of each character in a given string
     */
    /*
    slen = strlen(argv[1]);
    for (i=0; i<slen; ++i)
    {
        clen = char_len(argv[1][i]);
        printf("Len: %d\n", clen);
    }
    */

    return 0;
}


int test_len()
{
    char clen = 0;
    int slen = 0;
    int i = 0;
    char two_byte1[4];
    char two_byte2[4];
    /* Set contents of strings */
    int *loc = &two_byte1;
    *loc = 0x00c2; /* reverse for little endian */

    *loc = &two_byte2;
    *loc = 0x00df; /* reverse for little endian */

    slen = strlen(two_byte2);
    for (i=0; i<slen; ++i)
    {
        clen = char_len(two_byte2[i]);
        printf("Len: %d\n", clen);
    }

    slen = strlen(two_byte1);
    for (i=0; i<slen; ++i)
    {
        clen = char_len(two_byte1[i]);
        printf("Len: %d\n", clen);
    }
}
