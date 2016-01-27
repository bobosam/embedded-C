#include <stdio.h>

void checkInput(int matches);

int main(void)
{
    int n, matches;
    
    printf("n --> ");
    matches = scanf("%d", &n);
    checkInput(matches);
    
    if (1 > n || 20 < n)
    {
        printf("Wrong number!");
        exit(1);
    }
    
    int i;
    for (i = 0; i < n; i++)
    {
        int j;
        for (j = 1; j <= n; j++)
        {
            printf("%d ", i + j);
        }
        
        printf("\n");
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
