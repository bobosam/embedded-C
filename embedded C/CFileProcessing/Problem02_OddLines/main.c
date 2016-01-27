#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096
#define COUNT_OF_LINES 10

int main(void) 
{
    FILE *file = fopen("file.txt", "r");
    
    if (NULL == file)
    {
        fprintf(stderr, "Error opening file!");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    
    while (NULL == feof(file))
    {
        size_t readBytes = fread(buffer, 1, BUFFER_SIZE, file);
        buffer[readBytes] = '\0';
    }
    
    fclose(file);
    
    char *linesArr[COUNT_OF_LINES];
    int index = 0;
    linesArr[index] = strtok(buffer, "\n");
    while (NULL != linesArr[index])
    {
        index++;
        linesArr[index] = strtok(NULL, "\n");
    }
    
    int i;
    for (i = 0; i < index; i += 2)
    {
        printf("%s\n", linesArr[i]);
    }

    return 0;
}

