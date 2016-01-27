#include <stdio.h>
#include <math.h>
#include <string.h>

char *convertToBinary(int number, char *string);
void checkInput(int matches);

int main(void)
{
    int matches;
    unsigned long n;
    char binary[100] = "";
    char *result;
    
    printf("Enter a decimal number: ");
    matches = scanf("%lu", &n);
    checkInput(matches);
    
    result =  convertToBinary(n, binary);
    printf("%lu in decimal --> %s in binary", n, result);
    
    return 0;
}

char *convertToBinary(int number, char *string)
{
    if (number)
    {
        convertToBinary(number >> 1, string);
        strcat(string, (number & 1) ? "1" : "0");                      
    }
    
    return (char *)string;
}

void checkInput(int matches)
{
    if(1 != matches)
    {
        printf("Wrong number!");
        exit(1);
    }
}