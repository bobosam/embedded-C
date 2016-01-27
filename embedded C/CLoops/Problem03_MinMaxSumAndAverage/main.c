#include <stdio.h>
#include <float.h>

void checkInput(int matches);

int main(void) 
{
    int i, n, matches, number;
    double min = DBL_MAX, max = -DBL_MAX, sum = 0;
    printf("n --> ");
    matches = scanf("%d", &n);
    checkInput(matches);
    
    for (i = 0; i < n; i++)
    {
        printf("number %d --> ", i + 1);
        matches = scanf("%d", &number);
        checkInput(matches);
        if (number > max)
        {
            max = number;
        }
        
        if (number < min)
        {
            min = number;
        }

        sum += number;
    }
    
    printf("min = %.2f\n", min);
    printf("max = %.2f\n", max);
    printf("sum = %.2f\n", sum);
    printf("avg = %.2f\n", sum / n);

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
