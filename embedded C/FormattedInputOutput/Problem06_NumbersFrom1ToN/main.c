#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter count of numbers n: ");
    int matches = scanf("%d", &n);
    
    if (matches != 1)
    {
        printf("Wrong number !");
        
        return 1;
    }
    
    printf("|%s|%s|\n", "  n  ", "numbers");
    
    int i;
    for (i = 0; i < n; i++)
    {
        if(0 == i)
        {
            printf("|%-5d|%-7d|\n", n, i+1);
        }
        else
        {
            printf("|%5s|%-7d|\n", " ", i+1);
        }

    }



    return 0;
}

