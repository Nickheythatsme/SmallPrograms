
void encrypt(const char *key, char *data, unsigned long len)
{
    const char *key_start = key;
    unsigned long i = 0;
    
    for(; i < len; ++i)
    {
        *data -= 32;
        *data += *key;
        ++data; ++key;

        if(!*key)
        {
            key = key_start;
        }
    }

    return;
}

void decrypt(const char *key, char *data, unsigned long len)
{
    const char *key_start = key;
    unsigned long i = 0;

    for(; i < len; ++i)
    {
        *data += 32;
        *data -= *key;
        ++data; ++key;
        if(!*key)
        {
            key = key_start;
        }
    }

    return;
}
