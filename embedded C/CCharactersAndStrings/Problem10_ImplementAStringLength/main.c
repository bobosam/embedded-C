#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t str_len(const char *string);

int main(void)
{
    size_t length =  str_len("Soft");
    printf("string length --> %lu\n", length);
    
    length = str_len("SoftUni");
    printf("string length --> %lu\n", length);

    char buffer[10] = { 'C', '\0', 'B', 'a', 'b', 'y'};
    length = str_len(buffer);
    printf("string length --> %lu\n", length);
    
    char secondBuffer[] = { 'D', 'e', 'r', 'p', '\0'};
    length = str_len(secondBuffer);      
    printf("string length --> %lu", length); 
    
    return 0;
}

size_t str_len(const char *string)
{
    size_t length = 0;
        
    while ('\0' != string[length])
    {
        length++;       
    }
        
    return length;
}
