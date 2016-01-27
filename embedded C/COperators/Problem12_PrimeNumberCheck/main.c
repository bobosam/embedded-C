#include <stdio.h>
#include <math.h>

int main(void)
{
    int matches, isPrime = 1, number;
    
    printf("Number --> ");
    matches = scanf("%d", &number);
    if ( (1 != matches) || (100 < number))
    {
        printf("Wrong number!");

        return 1;
    }
    
    if (2 > number)
    {
        printf("Is prime --> false");
        
        return 0;
    }
       
    int i;
    for (i = 2; i <= (int)sqrt(number); i++)
    {
        if (number %i == 0) 
        {
            isPrime = 0;
        }
    }

    printf("Is prime --> %s", isPrime == 1 ? "true" : "false");
    
    return 0;
}

