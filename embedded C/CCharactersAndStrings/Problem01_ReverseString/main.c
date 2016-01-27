#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *inputString = NULL; 
    size_t len = 0;
    int size = 0;
    
    printf("Enter some string --> ");
    getline(&inputString, &len, stdin);
    size = strlen(inputString);   
    char reverse[size];    
    size--;
           
    int i;
    for (i = 0; i < size; i++)
    {
        reverse[i] = inputString[size - i - 1];
    }
    
    free(inputString);

    reverse[i] = '\0';
    printf("reverse --> %s", reverse);
    
    return 0;
}

