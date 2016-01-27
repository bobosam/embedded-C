#include <stdio.h>

void checkInput(int matches);

int main(void)
{
    unsigned long long numerator = 1, delimeter = 1, result;
    int i, n, matches;
    
    printf("n --> ");
    matches = scanf("%d", &n);
    checkInput(matches); 
    
    if (1 >= n || 100 <= n)
    {
        printf("Wrong number!");
        exit(1);
    }
    
    for (i = 1; i <= 2 * n; i++)
    {
        if (i > n + 1)
        {
            numerator *= i;
        }

        if (i <= n)
        {
            delimeter *= i;
        }
    }

    result = numerator / delimeter;
    printf("Catalan(n) --> %llu", result);
    
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
