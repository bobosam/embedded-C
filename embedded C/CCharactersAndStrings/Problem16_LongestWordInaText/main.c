#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COUNT 100

int main(void)
{
    char *inputLine = NULL;
    int len = 0;
    int maxIndeks = 0;
    int index = 0;
    char *wordsArr[MAX_COUNT];
    int maxLength = 0;
    
    printf("enter line --> ");
    getline(&inputLine, &len, stdin);
    int length = strlen(inputLine);
    if ('\n' == inputLine[length - 1])
    {
        inputLine[length - 1] = '\0';
    }

    wordsArr[index] = strtok(inputLine, " .,?!");
    while (NULL != wordsArr[index])
    {
        int wordLength = strlen(wordsArr[index]);
        if (wordLength > maxLength)
        {
            maxLength = wordLength;
            maxIndeks = index;
        }
        
        index++;
        wordsArr[index] = strtok(NULL, " .,?!");
    }

    printf("max word --> %s", wordsArr[maxIndeks]);
    
    free(inputLine);

    return 0;
}

