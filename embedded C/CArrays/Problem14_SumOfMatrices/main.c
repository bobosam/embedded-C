#include <stdio.h>

void check_input(int matches);
void print_matrix(int row, int col, int matrix[]);

int main(void)
{
    int row, col, number, matches;
    
    printf("row --> ");
    matches = scanf("%d", &row);
    check_input(matches);
    
    printf("col --> ");
    matches = scanf("%d", &col);
    check_input(matches);
    
    int firstMatrix[row][col];
    int secondMatrix[row][col];
    int sumMatrix[row][col];
    
    int i;
    for (i = 0; i < 2; i++) 
    {
        int j;
        for (j = 0; j < row; j++)
        {
            int k;
            for (k = 0; k < col; k++)
            {
                printf("matrix%d row%d col%d --> ", i + 1, j, k);
                matches = scanf("%d", &number);
                check_input(matches);
                
                if (0 == i) 
                {
                    firstMatrix[j][k] = number;
                }
                else
                {
                    secondMatrix[j][k] = number;
                    sumMatrix[j][k] = number + firstMatrix[j][k];
                }
            }
        }
    }
            
    printf("first matrix\n");
    print_matrix(row, col, *firstMatrix);
    
    printf("second matrix\n");
    print_matrix(row, col, *secondMatrix);
    
    printf("sum matrix\n");
    print_matrix(row, col, *sumMatrix);

    return 0;
}

void check_input(int matches)
{
    if (1 != matches)
    {
        printf("Wrong number!");
        exit(-1);
    }
}

void print_matrix(int row, int col, int matrix[])
{
    int i;
    for (i = 0; i < row; i++) 
    {
        int j;
        for (j = 0; j < col; j++) 
        {
            printf("%d ", matrix[i*col + j]);
        }

        printf("\n");
    }
}

