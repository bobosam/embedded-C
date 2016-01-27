#include <stdio.h>

int main(void)
{
    int n, k, matches;
    unsigned long long denominator = 1, numerator = 1, result;
    
    printf("n --> ");
    matches = scanf("%d", &n);
    checkInput(matches);
    printf("k --> ");
    matches = scanf("%d", &k);
    checkInput(matches);
    if (k >=n || 100 <= n || 1 >= k)
    {
        printf("Wrong numbers");
        exit(1);
    }

    int i;
    for (i = 1; i <= n; i++)
    {
        if (i <= k ) {
            denominator *= i;
        }
        
        if (i > (n - k))
        {
            numerator *= i;
        }
    }
    
    result = numerator / denominator;
 
    printf("n!/(k!*(n-k)!) --> %llu", result);
    
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
