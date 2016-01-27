#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void recursive_string_reverse(char* string, char* reverseString, int lenght, int index);

int main(void)
{
    char string[BUFFER_SIZE];
     char reverseString[BUFFER_SIZE];
    
    printf("string --> ");
    fgets(string, BUFFER_SIZE, stdin);
    int lenght = strlen(string);
    if ('\n' == string[lenght-1])
    {
        string[lenght- 1] = '\0';
        lenght = strlen(string);
    }

    recursive_string_reverse(string, reverseString, lenght, 0);
    
    printf("String --> %s recursive --> %s", string, reverseString);
    

    return 0;
}

void recursive_string_reverse(char* string, char* reverseString, int lenght, int index)
{
    if (index < lenght)
    {
        reverseString[index] = string[lenght - 1 - index];
        recursive_string_reverse(string, reverseString, lenght, index + 1);
    }
    
    if (index == lenght)
    {
        reverseString[index] = '\0';
    }
}

