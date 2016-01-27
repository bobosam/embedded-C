#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096
#define NUMBERS_STEP_INDEX 3

int main(void) 
{
    int row = 0;
    char buffer[BUFFER_SIZE];
    
    FILE *file = fopen("program.c", "r");
    FILE *dest = fopen("modified.c", "w");
    
    if ((NULL == file) || (NULL == dest) )
    {
        fprintf(stderr, "File not open!");
        return 1;
    }
    
    int index = 2;
    
    buffer[0] = '0';
    buffer[1] = ' ';
    
    while (1)
    {
        char ch = fgetc(file);
        if (feof(file))
        {
            break;
        }
        
        if(ch == '\n')
        {
            buffer[index]= ch;
            row++;
            char tmp[NUMBERS_STEP_INDEX];
            sprintf(tmp, "%d ", row);
            strncat(buffer, tmp, 2);
            index += NUMBERS_STEP_INDEX;
        }
        else
        {
            buffer[index] = ch;
            index++;
        }
    }

    buffer[index-NUMBERS_STEP_INDEX] = '\0';
    
    fwrite(buffer, 1, index - NUMBERS_STEP_INDEX, dest);
    free(file);
    free(dest);
    
    return 0;    
}

