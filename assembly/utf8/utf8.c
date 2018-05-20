#include <stdlib.h>
#include <stdio.h>

unsigned char char_len(char c)
{

 /*  len      1st byte
 *  1 bytes  0xxxxxxx
 *  2 bytes  110xxxxx
 *  3 bytes  1110xxxx
 *  4 bytes  11110xxx
 *
 *  part of mult-byte char: 10xxxxxx
 */
    unsigned char result = 0xf0 & c;
    switch(result)
    {
        /* beginning of one byte character */
        case 0x00:
            return 1;
        /* beginning of two byte character */
        case 0xc0:
            return 2;
        /* beginning of three byte character */
        case 0xe0:
            return 3;
        /* beginning of four byte character */
        case 0xf0:
            return 4;
    }
    /* part of a mult-byte character */
    /* case 0x80: */
        return 0;
}
