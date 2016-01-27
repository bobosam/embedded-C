#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 5

char *read_line();

int main(void)
{
    char *line = read_line();
    printf("line --> %s", line);
    
    free(line);

    return 0;
}

char *read_line()
{
    int reallocSize = INITIAL_SIZE;
    char *readLine = malloc(INITIAL_SIZE);
    if (NULL == readLine)
    {
        printf("Out of memory!");
    }
    
    char readChar;
    int index = 0;
    
    readChar = getchar();
    
    while(('\n' != readChar) && (EOF != readChar))
    {
        readLine[index]= readChar;
        index++;
        if (index == reallocSize)
        {
            reallocSize *= 2;
        }

        char *newLine = realloc(readLine, reallocSize);
        if (NULL == newLine)
        {
            printf("Out of memory!");
            exit(1);
        }
        
        readLine = newLine;
        readChar = getchar();      
    }
    
    readLine[index] = '\0';
    
    return readLine;
}
