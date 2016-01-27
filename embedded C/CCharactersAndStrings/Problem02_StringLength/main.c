#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE_SIZE 20

int main(void)
{
    char *resultString = NULL;
    size_t len = 0;
    
    printf("enter line --> ");
    getline(&resultString, &len, stdin);  
    int size = strlen(resultString);
    
    if (LINE_SIZE + 1 > size)
    {
        int i;
        for (i = size -1; i < LINE_SIZE; i++)
        {
            resultString[i] = '*';
        }
    }

    resultString[LINE_SIZE] = '\0'; 
    printf("result --> %s", resultString);
    
    free(resultString);

    return 0;
}

