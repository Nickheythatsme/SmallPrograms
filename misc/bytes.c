#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    size_t size;
    char *temp;
    int i;

    if (argc < 2)
    {
        printf("Usage: ./bytes [strings] [to] [test]\n");
        return 0;
    }

    for (i=1; i < argc; ++i)
    {
        size=0;
        temp=argv[i];
        while (*temp)
        {
            ++size;
            ++temp;
        }
        printf("String: %s\nBytes: %lu\n", argv[i], size);
    }
    return 0;


}
