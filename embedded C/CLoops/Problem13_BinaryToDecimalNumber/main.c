#include <stdio.h>
#include <math.h>
#include <string.h>

unsigned long binaryDecimal(char number[100]);
void checkInput(int matches);

int main(void)
{
    int matches;
    unsigned long result;
    char number[100];
    
    printf("Enter a binary number: ");
    matches = scanf("%99s", number);
    checkInput(matches);
    
    result = binaryDecimal(number);
    printf("%s in binary --> %lu in decimal", number, result);
    
    return 0;
}

unsigned long binaryDecimal(char number[100])
{
    unsigned long decimal=0;
    
    int i, size;
    size = strlen(number);
    for (i = 0; i < size; i++)
    {
        if (number[size - i -1] == '1') 
        {
            decimal += pow(2, i);
        }

    }


    return decimal;
}

void checkInput(int matches)
{
    if(1 != matches)
    {
        printf("Wrong number!");
        exit(1);
    }
}