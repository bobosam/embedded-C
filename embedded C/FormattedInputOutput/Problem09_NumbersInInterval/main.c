#include <stdio.h>

int main(void)
{
    int start, end, p=0; 
    
    printf("Enter number for start --> ");
    int firstMatches = scanf("%d", &start);
    printf("Enter number for end --> ");
    int secondMatches = scanf("%d", &end);
    
    if ((1 != firstMatches) || (1 != secondMatches))
    {
        printf("Wrong numbers !");
        return 1;
    }
    
    int i;
    for (i = start; i <= end; i++)
    {
        if (0 == i %5)
        {
            p++;
        }
    }
    
    printf("Count of numbers in interval from %d to %d is %d.\n", start, end, p);


    return 0;
}

