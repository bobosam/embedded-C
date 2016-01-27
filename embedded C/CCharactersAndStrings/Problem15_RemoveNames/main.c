#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMES_MAX_LENGTH 50

int main(void)
{
    char *inputLine = NULL;
    char *removeLine = NULL;
    int inputLen = 0;
    int removeLen = 0;   
    char *namesArr[NAMES_MAX_LENGTH];
    char *removeNamesArr[NAMES_MAX_LENGTH];
    int indexRemove = 0;
    int indexName = 0;
    
    printf("enter names line --> ");
    getline(&inputLine, &inputLen, stdin);
    int length = strlen(inputLine);
    if ('\n' == inputLine[length-1]) 
    {
        inputLine[length - 1] = '\0';
    }
    
    printf("enter names for remoove line --> ");
    getline(&removeLine, &removeLen, stdin);
    length = strlen(removeLine);
    if ('\n' == removeLine[length-1]) 
    {
        removeLine[length - 1] = '\0';
    }
    
    removeNamesArr[indexRemove] = strtok(removeLine, " ");
    while (NULL != removeNamesArr[indexRemove])
    {
        indexRemove++;
        removeNamesArr[indexRemove] = strtok(NULL, " ");
    }

    namesArr[indexName] = strtok(inputLine, " ");
    while (NULL != namesArr[indexName]) 
    {
        int check = 0;
        int i;
        for (i = 0; i < indexRemove; i++)
        {
            if (0 == strcmp(namesArr[indexName], removeNamesArr[i]))
            {
                check = 1;
            }
        }
        
        if (0 == check) 
        {
            printf("%s ", namesArr[indexName]);
        }

        indexName++;
        namesArr[indexName] = strtok(NULL, " ");
    }
    
    free(removeLine);
    free(inputLine);

    return 0;
}

