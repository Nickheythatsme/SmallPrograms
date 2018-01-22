/* Nick Grout 10/10/17
 *
 * This program reads the FILE stream and prints it.
 */
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char* argv[])
{
    FILE* in;
    char temp_read[50];

    if( argc <= 1 )
    {
        printf("Usage: ./read_rand [file_in]\n");
        return 1;
    }

    /* Open and check the file */
    in = fopen(argv[1],"r");
    if(!in) return 1;

    while(1)
    {
        if( fgets(temp_read,50,in) )
            printf("%s",temp_read);
    }
    return 0;
}
