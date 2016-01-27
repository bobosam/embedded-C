#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 4

char *read_line();

int main(void)
{
    char *charline = read_line();
    
    printf("line --> %s", charline);
    
    free(charline);

    return 0;
}

char *read_line()
{
    char c;
    int size = INITIAL_SIZE;
    
    char *line = malloc(INITIAL_SIZE);
    if (NULL == line)
    {
        printf("Out of memory!");
        exit(1);
    }

    size_t index = 0;
    do
    {
        c = getchar();
        line[index] = c;
        index++;
        if (index == size)
        {
            size *= 2;
            char *newArray = realloc(line, size);
            if(NULL == newArray)
            {
                printf("Out of memory!");
                exit(1);
            }

            line = newArray;
        }   
        
    }while ((c != '\n') && (c != '\0'));
    
    line[index-1] = '\0';
    
    return line;
}

