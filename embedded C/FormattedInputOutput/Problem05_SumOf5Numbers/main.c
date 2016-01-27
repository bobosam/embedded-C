#include <stdio.h>

int main(void) 
{
    double firstNumber, secondNumber, thirdNumber, fourthlyNumber, fifthNumber, result = 0;
    
    int matches = scanf("%lf %lf %lf %lf %lf",
            &firstNumber, &secondNumber, &thirdNumber, &fourthlyNumber, &fifthNumber);
    
    if (matches != 5)
    {
        printf("Wrong input");
        
        return 1;
    }

    result = firstNumber + secondNumber + thirdNumber + fourthlyNumber + fifthNumber;
    
    printf("|%s|%-6s|\n", "numbers", "sum");
    printf("|%g %g %g %g %g    | %.2f|",
            firstNumber, secondNumber, thirdNumber, fourthlyNumber, fifthNumber, result);
    
    return 0;
}

