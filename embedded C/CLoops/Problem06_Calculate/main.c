#include <stdio.h>

int main(void)
{
    int n, k, matches;
    unsigned long long result = 1;

    printf("n --> ");
    matches = scanf("%d", &n);
    checkInput(matches);
    printf("k --> ");
    matches = scanf("%d", &k);
    checkInput(matches);
    if (k >= n || 100 <= n || 1 >= k)
    {
        printf("Wrong numbers!");
        exit(1);
    }

    int i;
    for (i = k +1; i <= n; i++) 
    {
        result *= i;
    }
    
    printf("n!/k! -- > %llu", result);

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

