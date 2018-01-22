void lower(char *s)
{
    while(*s)
    {
        if(*s >= 'A' && *s <= 'Z')
            *s += ' '; /* *s += 32 */
        ++s;
    }
    return;
}
