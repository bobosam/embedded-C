#include <stdio.h>

int main(void)
{
    double number, sum = 0;
    int n;
    printf("Enter count of numbers n: ");
    int matches = scanf("%d", &n);
    
    if (matches != 1)
    {
        printf("Wrong number !");
        
        return 1;
    }
    
    int i;
    for (i = 0; i < n; i++) 
    {
       matches = scanf("%lf", &number);
       if (matches != 1)
        {
            printf("Wrong number !");

            return 1;
        }
       
       sum += number;
    }

    printf("sum --> %.1f", sum);

    return 0;
}

