#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    char *text = "Sir Stanley Royce";
    size_t length = strlen(text);
    char destination[length];
    
    int i = 0, j = length - 1;
    while (i <= length)
    {
        destination[j] = text[i];
        j--;
        i++;
    }
    
    destination[length] = '\0';
    
    printf("%s", destination);
    
    return (EXIT_SUCCESS);
}
