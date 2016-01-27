#include <stdio.h>

void check_input(int matches);

int main(void)
{
    int dimension, number, matches, sum = 0;
    
    printf("dimension --> ");
    matches = scanf("%d", &dimension);
    check_input(matches);
    int matrix[2][dimension];
    
    int i;
    for (i = 0; i < 2; i++)
    {
        int j;
        for (j = 0; j < dimension; j++) 
        {
            printf("vector %d member %d --> ", i+1, j + 1);
            matches = scanf("%d", &number);
            check_input(matches);
            matrix[i][j] = number;
        }
    }
    
    int k;
    for (k = 0; k < dimension; k++)
    {
        sum += matrix[0][k] * matrix[1][k];
    }

    printf("dot product --> %d", sum);

    return 0;
}

void check_input(int matches)
{
    if (1 != matches)
    {
        printf("Wrong number!");
        exit(1);
    }
}

