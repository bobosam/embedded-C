#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COUNT_OF_WORDS 100
#define SIZE_OF_DELIMETER 2

int words_count(char *text, char *delimiter);

int main(void)
{
    char *text = NULL;
    int len = 0;
    char delimiter[SIZE_OF_DELIMETER];
    int count = 0;
    
    printf("enter text --> ");
    getline(&text, &len, stdin);
    printf("enter char --> ");
    fgets(delimiter, SIZE_OF_DELIMETER, stdin);
             
    count = words_count(text, delimiter);
    free(text);
    printf("count of words --> %d", count);
   
    return 0;
}

int words_count(char *text, char *delimiter)
{      
    int index = 0;
    char *wordsArr[MAX_COUNT_OF_WORDS];
    
    wordsArr[index] = strtok(text, delimiter);
    while (NULL != wordsArr[index])
    {
        index++;
        wordsArr[index] = strtok(NULL, delimiter);
    }
       
    return index;
}
