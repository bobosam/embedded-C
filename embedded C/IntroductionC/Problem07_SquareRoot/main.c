#include <stdio.h>
#include <math.h>

int main(void) 
{
    double number;
    
    printf("Enter number: ");
    scanf("%lf", &number);
    printf("Square root of %lf is %lf\n", number, sqrt(number));
    
    return 0;
}

