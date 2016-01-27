#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COUNT_PARTS 50
#define SOURCE_NAME "Book_2.txt"
#define DESTINATION_NAME "Test"
#define DELIMITER "ЧАСТ"

int main(void)
{
    size_t delimiterLength = strlen(DELIMITER);
    
    printf("%lu", delimiterLength);
    FILE *text = fopen(SOURCE_NAME, "r");
    if (NULL == text) 
    {
        printf("File not open");
    }

    int index = 0;
    char fileName[100];
    char *line = NULL;
    size_t size = 0;
    sprintf(fileName, "parts/%s_%d.txt", DESTINATION_NAME, index);
    FILE *dest = fopen(fileName, "w");
    ssize_t length = getline(&line, &size, text);

    while (!feof(text))
    {

        if (0 != strncasecmp(line, DELIMITER, delimiterLength)) 
        {
            fwrite(line, 1, length, dest);
        } 
        else
        {
            index++;
            fclose(dest);
            sprintf(fileName, "parts/%s_%d.txt", DESTINATION_NAME, index);
            FILE *dest = fopen(fileName, "w");
            fwrite(line, 1, length, dest);
        }

        length = getline(&line, &size, text);

        if (index > MAX_COUNT_PARTS) 
        {

            printf("ERROR ...");
            exit(1);
        }
    }

    fclose(text);
    fclose(dest);

    return 0;
}

