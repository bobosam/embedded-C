#include <stdio.h>
#include <string.h>

char *strn_cpy(char *buffer, char *text, int size);

int main(void)
{
    char buffer[100];   
   
    strn_cpy(buffer, "SoftUni", 7);  
    printf("%s\n", buffer);
    
    strn_cpy(buffer, "SoftUni", 3);  
    printf("%s\n", buffer);
    
    strn_cpy(buffer, "C is cool", 0);  
    printf("%s\n", buffer);

    return 0;
}

char *strn_cpy(char *buffer, char *text, int size)
{
    int len = strlen(text);
    if (size > len)
    {
        size = len;
    }

    int i;
    for (i = 0; i < size; i++)
    {
        buffer[i] = text[i];
    }
    
    buffer[i] = '\0';
    
    if (0 == strlen(buffer))
    {
        char empty[] = "(empty string)";
        int i;
        for (i = 0; i < strlen(empty); i++)
        {
            buffer[i] = empty[i];
        }
        
        buffer[i] = '\0';
        
        return buffer;
    }
    
    return buffer;
}

