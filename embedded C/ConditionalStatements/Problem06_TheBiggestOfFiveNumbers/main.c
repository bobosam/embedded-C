#include <stdio.h>
#include <float.h>

void checkNumber(int matches);

int main(void)
{
    double number, biggest;
    int matches, counter = 1;
    
    biggest = -DBL_MAX;
    
    printf("Number %d --> ", counter);
    matches = scanf("%lf", &number);
    checkNumber(matches);
    if (number > biggest)
    {
        biggest = number;
    }
    
    counter++;
    printf("Number %d --> ", counter);
    matches = scanf("%lf", &number);
    checkNumber(matches);
    if (number > biggest)
    {
        biggest = number;
    }
    
    counter++;
    printf("Number %d --> ", counter);
    matches = scanf("%lf", &number);
    checkNumber(matches);
    if (number > biggest)
    {
        biggest = number;
    }
    
    counter++;
    printf("Number %d --> ", counter);
    matches = scanf("%lf", &number);
    checkNumber(matches);
    if (number > biggest)
    {
        biggest = number;
    }
    
    counter++;
    printf("Number %d --> ", counter);
    matches = scanf("%lf", &number);
    checkNumber(matches);
    if (number > biggest)
    {
        biggest = number;
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

