#include <stdio.h>
#include <float.h>

void checkNumber(int matches);

int main(void)
{
    double number, biggest;
    int matches, i;
    
    biggest = -DBL_MAX;
    for (i = 0; i < 3; i++)
    {
        printf("Number %d --> ", i + 1);
        matches = scanf("%lf", &number);
        checkNumber(matches);
        
        if (number > biggest)
        {
            biggest = number;
        }
    }   
    
    printf("biggest --> %.1f", biggest);
    
    return 0;
}

void checkNumber(int matches)
{
    if (1 != matches)
    {
        printf("Wrong number!");
        exit(1);
    }   
}

