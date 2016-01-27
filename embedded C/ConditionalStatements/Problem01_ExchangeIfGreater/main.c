#include <stdio.h>

int main(void)
{
    int matchesA, matchesB;
    double a, b;
    
    printf("a --> ");
    matchesA = scanf("%lf", &a);
    printf("b --> ");
    matchesB = scanf("%lf", &b);
    if ((1 != matchesA) || 1 != matchesB)
    {
        printf("Wrong numbers!");
        
        return 1;
    }
    
    if (a > b)
    {
        printf("result --> %.1f %.1f", b, a);
    } 
    else
    {
        printf("result --> %.1f %.1f", a, b);
    }

    return 0;
}

