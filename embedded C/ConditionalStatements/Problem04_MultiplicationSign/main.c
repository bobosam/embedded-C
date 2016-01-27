#include <stdio.h>

void checkInput(int matches);

int main(void)
{
    double a, b, c;
    int matches;
        
    printf("a --> ");
    matches = scanf("%lf", &a);
    checkInput(matches);
    
    printf("b --> ");
    matches = scanf("%lf", &b);
    checkInput(matches);
    
    printf("c --> ");
    matches = scanf("%lf", &c);
    checkInput(matches);
    
    if (0 == (a * b * c))
    {
        printf("result --> 0");
        return 0;
    }
    else if (0 > a * b *c)
    {
        printf("result --> -");
        return 0;
    }
    else
    {
        printf("result --> +");
    }

    return 0;
}

void checkInput(int matches)
{
    if (1 != matches)
    {
        printf("Wrong number!");
        exit(1);
    }
}

