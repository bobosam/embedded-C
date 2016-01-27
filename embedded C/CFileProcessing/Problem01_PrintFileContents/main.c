#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

int main(void)
{
    FILE *file = fopen("file.txt", "r");
    
    if (NULL == file)
    {
        fprintf(stderr, "Error opening file");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    
    while (NULL == feof(file))
    {
        size_t readBytes = fread(buffer, 1, BUFFER_SIZE, file);
        buffer[readBytes] = '\0';
        printf("%s\n", buffer);
    }

    fclose(file);

    return 0;
}

