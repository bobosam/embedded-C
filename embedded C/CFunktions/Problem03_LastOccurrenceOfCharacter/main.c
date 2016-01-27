#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 200

int last_occurrence(char character, char inputLine[]);

int main(void)
{
    int position;
    char inputLine[BUFFER_SIZE], character;
    
    printf("Enter string --> ");
    fgets(inputLine, BUFFER_SIZE, stdin);
    printf("Enter character: ");
    character = getchar();
    
    position = last_occurrence(character, inputLine);
    
    printf("position --> %d", position);
    
    return 0;
}

int last_occurrence(char character, char inputLine[])
{
    int strSize = strlen(inputLine);
    
    int i;
    for (i = strSize - 1; i >= 0; i--)
    {
        if (inputLine[i] == character)
        {
            return i;
        }
    }
    
    return -1;
}

