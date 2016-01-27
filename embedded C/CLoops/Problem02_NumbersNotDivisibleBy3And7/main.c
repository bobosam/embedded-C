#include <stdio.h>

void checkInput(int matches);

int main(void)
{
    int n, i, matches;
    
    printf("n --> ");
    matches = scanf("%d", &n);
    checkInput(matches);
    
    for (i = 1; i <= n; i++)
    {
        if ((0 == i %3) || (0 == i %7))
        {
            continue;
        }

        printf("%d ", i);
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

