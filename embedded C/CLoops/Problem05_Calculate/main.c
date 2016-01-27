#include <stdio.h>

int main(void)
{
    int n, x, matches, numerator = 1, denominator;
    double result;
    
    printf("n --> ");
    matches = scanf("%d", &n);
    checkInput(matches);
    printf("x --> ");
    matches = scanf("%d", &x);
    checkInput(matches);
    
    denominator = x;
    result = 1 + (double)numerator / denominator;
    
    int i;
    for (i = 2; i <= n; i++)
    {
        numerator = i * numerator;
        denominator *= x;
        result += (double)numerator / denominator;
    }

    printf("s --> %.5f", result);

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

