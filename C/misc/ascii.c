#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH   10L
#define START_C ' '
#define END_C   '~'

static char fmt_d[] = "%c %3d   ";
static char fmt_x[] = "%c %3x   ";
static char fmt_o[] = "%c %3o   ";

char*** make_array(long width, long height, const char *fmt)
{
    long i;
    long j;
    unsigned char c = START_C;
    size_t fmt_len = strlen(fmt) + 1;
    char ***array = (char***) malloc(sizeof(char**)*height + 1);

    for(i = 0; i < height; ++i)
    {
        array[i] = (char**) malloc(sizeof(char*) * width);
        for(j = 0; j < width; ++j)
            array[i][j] = (char*) malloc(sizeof(char) * fmt_len);
    }

    for(i = 0; i < height ; ++i)
    {
        c = START_C + i;
        for(j = 0; j < width && c < END_C; ++j)
        {
            sprintf(array[i][j],fmt,c,c);
            c += (char) height;
        }
        for(; j < width; ++j)
            array[i][j][0] = '\0';
    }

    return array;
}

int main(int argc, char *argv[])
{
    long i;
    long j;
    long height = (long) ((END_C - START_C) / WIDTH) + ((END_C - START_C) % WIDTH != 0);
    char ***array;
    char convert_to = 'd';

    if( argc > 1 )
        convert_to = argv[1][0];

    switch(convert_to)
    {
        case 'x':
            array = make_array(WIDTH, height,fmt_x);
            break;
        case 'o':
            array = make_array(WIDTH, height,fmt_o);
            break;
        case 'd':
        default:
            array = make_array(WIDTH, height,fmt_d);
            break;
    }
    

    for(i = 0; i < height; ++i)
    {
        for(j = 0; j < WIDTH; ++j)
        {
            printf("%s",array[i][j]);
            free(array[i][j]);
        }
        free(array[i]);
        printf("\n");
    }

    free(array);
    return 0;
}
