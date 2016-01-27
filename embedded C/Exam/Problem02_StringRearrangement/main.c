#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_BUFFER_LENGTH 64

char *get_line(char **bufferPtr, size_t *bufSize);

int main(void)
{
    char *line = NULL;
    size_t size = 0;
    get_line(&line, &size);
    size_t len = strlen(line);
    char *result =(char *)calloc(len, 1);
    if (NULL == result)
    {   
        printf("Out of memory!");
        exit(1);
    }
    
    char *token = strtok(line, "|");
    while (NULL != token)
    {
        char *open = strchr(token, '{');
        char *close = NULL;
        if (NULL != open)
        {
            close = strchr(open, '}');
        }

        if ((NULL != open) && (NULL != close))
        {
            size_t data = close - open -1;
            strncat(result, open + 1, data);
        }

        token = strtok(NULL, "|");
    }
    
    int resultLen = strlen(result);
    char *commandLine = NULL;
    size_t commandSize = 0;
    get_line(&commandLine, &commandSize);
    
    while (0 != strcmp("end", commandLine)) 
    {
        int firstPoint, secondPoint, count;
        if (3 == sscanf(commandLine, "swap %d %d %d",
                &firstPoint, &secondPoint, &count));
        {
            if ((0 <= firstPoint) && (0 <= secondPoint) && (0 <= count) &&
                    (firstPoint + count) < resultLen && (secondPoint + count) < resultLen)
            {
                char tmp[count];
                strncpy(tmp, result + firstPoint, count);
                strncpy(result + firstPoint, result + secondPoint, count);
                strncpy(result + secondPoint, tmp, count);
            }
            else
            {
                printf("Invalid command parameters\n");
            }
        }
                
        get_line(&commandLine, &commandSize);
    }
    
    printf("%s\n", result);
    
    free(commandLine);
    free(line);
    free(result);
       
    return 0;
}

char *get_line(char **bufferPtr, size_t *bufSize)
{
    char *result = *bufferPtr;
    size_t size = *bufSize;
    if (result == NULL)
    {
        result = (char *)malloc(INITIAL_BUFFER_LENGTH);
        size = INITIAL_BUFFER_LENGTH;
         if (!result)
            return NULL;
    }
  
    size_t i = 0;
    char ch = getchar();
    while (ch != '\n' && ch != EOF)
    {
        if (i == size - 1)
        {
            char *resized = (char *)realloc(result, 2 * size);
            if (!resized)
            {
                return NULL;
            }
            
            result = resized;
            size *= 2;
        }
        
        result[i] = ch;
        i++;
        
        ch = getchar();
    }
    
    result[i] = '\0';
    *bufferPtr = result;
    *bufSize = size;
    
    return result;
}

