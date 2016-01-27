#include <stdio.h>

int main(void)
{
    int number, digit, matchesNumber, matchesDigit, i, counter = 1,result;
    
    printf("Number ? --> ");
    matchesNumber = scanf("%d", &number);
    printf("Digit ? --> ");
    matchesDigit = scanf("%d", &digit);
    if ((1 != matchesDigit) || (1 != matchesNumber))
    {
        printf("Wrong numbers!");
        return 1;
    }
    
    if (0 == number && 1 == digit)
    {
        printf("Result --> 0");
        
        return 0;
    }
    
    if (0 > number) 
    {
        number = number * (-1);
    }
   
    while (number) 
    {
        if (counter == digit)
        {
            result = number %10;
            printf("Result --> %d", result);
            
            return 0;
        }
        
        number = number / 10;
        if (1 > number)
        {
            printf("Result -- > %s", "-");
        }
        
        counter++;
    }

    return 0;
}

