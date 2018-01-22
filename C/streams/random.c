/* Nick Grout 10/10/17
 *
 * This is for creating a file stream of random numbers. The other program
 * reads these to test a simple stream
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int write_num(const char* file_out, int num);

int main(int argc, char* argv[])
{
    int modular;
    int temp_rand;
    FILE* out;

    if( argc <= 2 )
    {
        printf("Usage: ./random [max] [file_out]\n");
        return 1;
    }
    sscanf(argv[1],"%d",&modular);

    /* Clear the file since last time */
    out = fopen(argv[2],"w");
    fclose(out);

    /* Get and write the number */
    while(1)
    {
        temp_rand = rand() % modular;
        write_num(argv[2], temp_rand);
        sleep(1);
    }
}

int write_num(const char* file_out, int num)
{
    FILE* out;

    out = fopen(file_out,"a");
    fprintf(out, "%d\n", num);
    fclose(out);
    return 1;
}
