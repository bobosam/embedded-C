#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *text = NULL;
    char *words = NULL;
    int textLen = 0;
    int wordsLen = 0;
    char *wordsArr[10];
    int count = 0;  
       
    printf("banned words --> ");
    getline(&words, &wordsLen, stdin);
    printf("text --> ");
    getline(&text, &textLen, stdin);
    
    wordsArr[count] = strtok(words, ", ");
    while (NULL != wordsArr[count])
    {
        count++;
        wordsArr[count] = strtok(NULL, ", ");
    }
    
    int i;
    for (i = 0; i < count; i++)
    {
        int size = strlen(wordsArr[i]);
        if ('\n' == wordsArr[i][size - 1])
        {
            wordsArr[i][size - 1] = '\0';
            size--;
        }
        
        char *matches;
        char *ptr = text;
        do
        {
            matches = strstr(ptr, wordsArr[i]);
            if (NULL != matches) 
            {
                int i;
                for (i = 0; i < size; i++)
                {
                    *(matches + i) = '*';
                }
            }
            
            ptr = matches + size;
        }while(NULL != matches);
    }

    printf("result --> %s", text);
    
    int j;
    for (j = 0; j < count; j++)
    {
        free(wordsArr[count]);
    }

    free(text);
    free(words);
    
    return 0;
}

