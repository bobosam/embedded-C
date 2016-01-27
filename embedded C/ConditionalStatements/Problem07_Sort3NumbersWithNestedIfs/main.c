#include <stdio.h>

void checkMatches(int matches);
void swap (double *firstNumber, double *secondNumber);

int main(void)
{
    double a, b, c;
    int matches;
    
    printf("a --> ");
    matches = scanf("%lf", &a);
    checkMatches(matches);
    
    printf("b --> ");
    matches = scanf("%lf", &b);
    checkMatches(matches);
    
    printf("c --> ");
    matches = scanf("%lf", &c);
    checkMatches(matches);
    
    if (b > a)
    {
        swap(&a, &b);
    }
    
    if (c > a)
    {
        swap(&a, &c);
    }

    if (c > b)
    {
        swap(&b, &c);
    }

    printf("result %.1f %.1f %.1f", a, b, c);
    
    return 0;
}

void checkMatches(int matches)
{
    if (1 != matches)
    {
        printf("Wrong number!");
        
        exit(1);
    }
}

void swap (double *firstNumber, double *secondNumber)
{
    double temp;
    temp = *firstNumber;
    *firstNumber = *secondNumber;
    *secondNumber = temp;
}