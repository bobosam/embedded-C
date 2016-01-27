#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 50

double revers_number(char number[BUFFER_SIZE], int* error);

int main(void)
{
    int error;
    char number[BUFFER_SIZE];
    double reverseNumber;
    
    printf("Enter number --> ");
    fgets(number, BUFFER_SIZE, stdin);
    
    reverseNumber = revers_number(number, &error);
    if (0 == error)
    {
        printf("output --> %.3f", reverseNumber);
    }
    else
    {
        printf("invalid format");
    }
     
    return 0;
}

double revers_number(char number[BUFFER_SIZE], int* error)
{
    char reverseNumber[BUFFER_SIZE];
    double num;
    
    int size = strlen(number);
    int i, index = 0;
    for (i = size - 1; i >= 0; i--)
    {
        reverseNumber[index] = number[i];
        index++;
    }
    
    num = atof(reverseNumber);
    if (0 == num)
    {
        *error = 1;
        return 0;
    }

    *error = 0;
    
    return num;      
}

