#include <stdio.h>
#include <stdlib.h>

void digit_hate(char *inputString, char *resultString, int bytes_read, int *digitsCount);

int main(void)
{
    int bytes_read;
    int nbytes = 200;
    char *my_string, *result;
    int digitsCount = 0;

    printf("Please enter a line of text --> ");

    my_string = (char *) malloc (nbytes + 1);
    result = (char *) malloc(nbytes + 1);
        
    if (my_string && result)
    {
        bytes_read = getline (&my_string, &nbytes, stdin);
        if (bytes_read == -1)
        {
          puts ("ERROR!");
        }

        digit_hate(my_string, result, bytes_read, &digitsCount);

        printf("result string --> %s\n", result);
        printf("count of replaced digits --> %d", digitsCount);
        
        free(result);
        free(my_string);
    }
        
    return 0;
}

void digit_hate(char *inputString, char *resultString, int bytes_read, int *digitsCount)
{
    int i;
    for (i = 0; i < bytes_read; i++)
    {
        if (('0' <= *(inputString + i) ) && ('9' >= *(inputString + i)))
        {
            *(resultString + i) = '/';
            (*digitsCount)++;
        }
        else
        {
            *(resultString + i) = *(inputString + i);
        }
    } 
    
    *(resultString + (bytes_read - 1)) = '\0';
}

