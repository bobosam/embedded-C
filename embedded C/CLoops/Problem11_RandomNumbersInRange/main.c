#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void checkInput(int matches);

int main(void) 
{
    int n, min, max, matches, number;
    time_t t;
    
    printf("n --> ");
    matches = scanf("%d", &n);
    checkInput(matches);
    printf("min --> ");
    matches = scanf("%d", &min);
    checkInput(matches);
    printf("max --> ");
    matches = scanf("%d", &max);
    checkInput(matches);
    if (min > max)
    {
        printf("Wrong numbers!");
    }
    
    srand((unsigned) time(&t));

    printf("random numbers --> ");
    
    int i;
    for (i = 0; i < n; i++)
    {
        number = (rand() % (max+1-min))+min;
        printf("%d ", number);
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