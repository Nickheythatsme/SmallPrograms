#include <stdlib.h>
#include <stdio.h>


/*
 * Working character length function. Determines the length of the
 * character by the first byte
 */
size_t char_len(signed char f)
{
    size_t i = 0;
    if (f >= 0)
        return 1;

    while (f < 0)
    {
        f <<= 1;
        ++i;
    }
    return i;
}

/*
 * Return the difference between two strings at n locations after where the
 * pointers initially point
 */
size_t u_strncmp(const char *lhs, const char *rhs, size_t n)
{
    char diff = *lhs - *rhs;
    while (*lhs && *rhs && !diff && n > 0)
    {
        ++lhs; ++rhs;
        diff = *lhs - *rhs;
        --n;
    }
    return diff;
}

/*
 * Test the string against a string of delimiters
 * Returns 1 if a character of str is found in delims
 * Returns 0 otherwise
 */
size_t delims_str(const char *str, const char *delims)
{
    size_t sc_len; /* len of current str character */
    size_t dc_len; /* len of current delims character */
    const char *delim_head = delims;

    while (*str)
    {
        sc_len = char_len(*str);
        delims = delim_head;

        while (*delims)
        {
            dc_len = char_len(*delims);

            /* Only test if they're the same length */
            if (sc_len == dc_len)
                /* test if the characters are equal */
                if (!u_strncmp(str, delims, sc_len))
                    return 1;

            /* Increment the pointers to the next character */
            delims += (dc_len) ? dc_len : 1;
        }
        str += (sc_len) ? sc_len : 1;
    }
    return 0;
}

/*
 * Test if a single character is found in the delims
 */
int delims_char(const char *c, const char *delims)
{
    size_t c_len = char_len(*c); /* length of c */
    size_t d_len;  /* length of current delimiter character */

    if (c_len == 0)
        return -1;
    while (*delims)
    {
        d_len = char_len(*delims);
        if (c_len == d_len)
            if (!u_strncmp(c, delims, c_len))
                return 1;
        delims += d_len;
    }
    return 0;
}
