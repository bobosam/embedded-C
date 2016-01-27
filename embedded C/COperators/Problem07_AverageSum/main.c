#include <stdio.h>

int main(void)
{
    double number, sum = 0, average;
    int i, matches;
    
    for (i = 0; i < 3; i++)
    {
        printf("Please enter number%d: ", i + 1);
        matches = scanf("%lf", &number);
        if (1 != matches)
        {
            printf("Wrong number!");
            return 1;
        }

        sum += number;
    }

    average = sum / 3;
    printf("Average --> %.5f", average);
    
    return 0;
}

