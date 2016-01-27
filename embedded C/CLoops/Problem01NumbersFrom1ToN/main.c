#include <stdio.h>

void checkInput(int matches);

int main(void)
{
    int n, matches, i;
    
    printf("n --> ");
    matches = scanf("%d", &n);
    checkInput(matches);
    
    for (i = 1; i <= n; i++)
    {
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

