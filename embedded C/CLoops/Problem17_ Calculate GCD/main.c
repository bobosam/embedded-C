#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void checkInput(int matches);

int main(void)
{
    int a, b, matches, tmp, gcd, rem = 1;
    
    printf("a --> ");
    matches = scanf("%d", &a);
    checkInput(matches);
    printf("b --> ");
    matches = scanf("%d", &b);
    checkInput(matches);
    
    a = abs(a);
    b = abs(b);
    
    if (b > a)
    {
        tmp = a;
        a = b;
        b = tmp;
    }

    do
    {
        if (0 == a %b)
        {
            gcd = b;
            rem = 0;
        }
        else
        {
         tmp = a;
         a = b;
         b = tmp %b;
        }

        
    }while(0 != rem);
    
    printf("GCD(a, b) --> %d", gcd);

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

