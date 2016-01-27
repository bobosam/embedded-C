#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *input = NULL;
    int len = 0;

    printf("input --> ");
    getline(&input, &len, stdin);
    int size = strlen(input) - 1;
    
    printf("result --> %c", input[0]);
    
    int i;
    for (i = 1; i < size; i++)
    {
        if (input[i] != input[i - 1])
        {
            printf("%c", input[i]);
        }
    }
    
    free(input);

    return 0;
}

