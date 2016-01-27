#include <stdio.h>

int main(void)
{
    int n, firstNumber = 0, secondNumber = 1, sum;
    
    printf("Enter count of numbers n:");
    
    int matches = scanf("%d", &n);
    if (1 != matches)
    {
        printf("Wrong number");
        
        return 1;
    }

    
    if (1 == n)
    {
        printf("%d", firstNumber);
    }
    
    if (2 <= n)
    {
        printf("%d %d ", firstNumber, secondNumber);
    }

    int i;
    for (i = 3; i <= n; i++)
    {
        sum = firstNumber + secondNumber;
        printf("%d ", sum);
        firstNumber = secondNumber;
        secondNumber = sum;
    }
     
    return 0;
}

