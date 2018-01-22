#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(const char *key, char *data, unsigned long len);
void decrypt(const char *key, char *data, unsigned long len);

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Usage: ./encrypt [key] [data]\n");
        exit(EXIT_FAILURE);
    }
    printf("Before encryption: %s\n",argv[2]);

    encrypt(argv[1],argv[2], strlen(argv[2]));
    printf("After encryption: %s\n",argv[2]);

    decrypt(argv[1],argv[2], strlen(argv[2]));
    printf("After decryption: %s\n",argv[2]);

    exit(EXIT_SUCCESS);
}
