#include <stdio.h>
#include <string.h>

char *convertToBinary(int number, char *string);

int main(void)
{
    int a;
    double b, c;
    char binary[10] = "";
    char *result;
    char resultWithZero[11];
    
    printf("Enter a --> ");
    scanf("%d", &a);
    printf("Enter b --> ");
    scanf("%lf", &b);
    printf("Enter c --> ");
    scanf("%lf", &c);
    
    if (0 > a || 500 < a)
    {
        printf("Invalid number a!");
        return 1;
        }
    
    result =  convertToBinary(6, binary);
    
    int i;
    for (i = 0; i < 10 - strlen(result); i++)
    {
        resultWithZero[i] = '0';
    }
    
    strcat(resultWithZero, result);

    
    printf("\n|%-10s|%-10s|%-10s|%-43s|\n", "a", "b", "c", "result");
    printf("|%-10d|%-10g|%0-10g|%-10x|%s|%10.2f|%-10.3f|", a, b, c, a, resultWithZero, b, c); 

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

