#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50

void check_input(int matches);

int main(void)
{
    int count, matches;
    
    printf("count of words --> ");
    matches = scanf("%d", &count);
    check_input(matches);
    getchar();
    
    char words[count][MAX_WORD_LENGTH];
    int i;
    for (i = 0; i < count; i++) 
    {
        fgets(words[i], MAX_WORD_LENGTH, stdin);
        int size = strlen(words[i]);
        if ('\n' == words[i][size - 1])
        {
            words[i][size - 1] = '\0';
        }
    }
    
    int maxCount = 0;
    char maxWord[MAX_WORD_LENGTH];

    for (i = 0; i < count; i++)
    {
        int counter = 0;
        int j;
        for (j = 0; j < count; j++) 
        {
            if (0 == strcmp(words[i], words[j]))
            {
                counter++;
            }
        }
        
        if (counter > maxCount)
        {
            maxCount = counter;
            strcpy(maxWord, words[i]);
        }
    }
    
    printf("count --> %d\n", maxCount);
    for (i = 0; i < maxCount; i++)
    {
        printf("%s\n", maxWord);
    }
    
    return 0;
}

void check_input(int matches)
{
    if (1 != matches)
    {
        printf("Wrong input!");
        exit(1);
    }
}