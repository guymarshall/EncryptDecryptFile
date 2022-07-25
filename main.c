#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *file_ptr;
    file_ptr = fopen(argv[1], "rb");

    FILE *encrypted_file_ptr;
    encrypted_file_ptr = fopen(argv[2], "wb");

    if (file_ptr == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    if (encrypted_file_ptr == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    // encrypt data (add to function in header)
    int c;
    while ((c = fgetc(file_ptr)) != EOF)
    {
        c = c ^ 42;
        fputc(c, encrypted_file_ptr);
    }

    fclose(file_ptr);
    fclose(encrypted_file_ptr);

    return 0;
}