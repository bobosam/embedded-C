#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 101

int main(void)
{
    int key, len, sum = 0;
    char line[MAX_BUFFER_SIZE];
    
    scanf("%d", &key);
    getchar();
    fgets(line, MAX_BUFFER_SIZE, stdin);
    
    len = strlen(line);
    if ('\n' == line[len - 1])
    {
        line[len - 1] = '\0';
        len = strlen(line);
    }

    int i;
    for (i = 0; i < len; i++)
    {
        char tmp = tolower(line[i]);
        if (tmp >= 'a' && tmp <= 'z')
        {
            tmp = tmp - 'a' + 1;
        }
        
        sum += tmp;
    }
    
    char digits[32];
    int index = 0;
    while (sum > 0) 
    {
        int digit = sum % key;
        digits[index] = '0' + digit;
        index++;
        sum = sum / key;
    }
    
    digits[index] = '\0';


    printf("%d", key);
    printf("%d", len);
    
    for (i = index - 1; i >= 0; i--)
    {
        printf("%c", digits[i]);
    }

    
    return 0;
}

