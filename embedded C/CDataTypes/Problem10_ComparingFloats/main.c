#include <stdio.h>
#include <math.h>

int main(void)
{
    double firstNumber, secondNumber;
    int equal;
    
    printf("Enter first number: ");
    scanf("%lf", &firstNumber);
    printf("Enter second number: ");
    scanf("%lf", &secondNumber);
    
    equal =  fabs(firstNumber-secondNumber) < 0.000001;
    
    printf("\n|%-10s|%-10s|%-10s|\n", "Number a", "Number b", "Equal");
    printf("\n|%-10f|%-10f|%-10s|\n", firstNumber, secondNumber, equal ? "true": "false");

    return 0;
}

