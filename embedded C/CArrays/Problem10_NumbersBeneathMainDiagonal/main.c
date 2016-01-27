#include <stdio.h>

void check_input(int matches);

int main(void)
{
    int size, matches, number;
    
    printf("size of matrix --> ");
    matches = scanf("%d", &size);
    check_input(matches);
    
    int matrix[size][size];
    int i;
    for (i = 0; i < size; i++)
    {
        int j;
        for (j = 0; j < size; j++)
        {
            printf("number %d,%d --> ", i, j);
            matches = scanf("%d", &number);
            check_input(matches);
            matrix[i][j] = number;
        }
    }
    
    printf("matrix:\n");
    for (i = 0; i < size; i++)
    {
        int j;
        for (j = 0; j < size; j++)
        {
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }
    
    printf("result:\n");
    int k;
    for (k = 0; k < size; k++)
    {
        int l;
        for (l = 0; l <= k; l++)
        {
            printf("%d ", matrix[k][l]);
        }

        printf("\n");
    }

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

