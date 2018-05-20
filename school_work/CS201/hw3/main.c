#include <stdlib.h>

char test();

int main(int argc, char**argv)
{
    int i;

    char arg = test();

    printf("%c", arg);
}
