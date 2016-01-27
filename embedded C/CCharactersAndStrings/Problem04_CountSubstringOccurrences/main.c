#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define SUBSTRING_BUFFER_SIZE 50

int main(void) 
{
    char *inputLine = NULL;
    int len = 0;
    char substring[SUBSTRING_BUFFER_SIZE];
    int index = 0;
    char *matches;
    int counter = 0;
    
    printf("input line --> ");
    getline(&inputLine, &len, stdin);
    printf("substring --> ");
    fgets(substring, SUBSTRING_BUFFER_SIZE, stdin);
    
    while ('\n' != inputLine[index]) 
    {
        inputLine[index] = tolower(inputLine[index]);
        index++;
    }
    
    index = 0;
    
    while ('\n' != substring[index]) 
    {
        substring[index] = tolower(substring[index]);
        index++;
    }
    
    substring[index] = '\0';
    
    char *ptr;
    ptr = inputLine;
    
    do
    {
        matches = strstr(ptr, substring);
        if (NULL != matches)
        {
            counter++;
        }
        
        ptr = matches +1;   
    }while(NULL != matches);
    
    printf("count of substring --> %d", counter);
    free(inputLine);
    
    return 0;
}

