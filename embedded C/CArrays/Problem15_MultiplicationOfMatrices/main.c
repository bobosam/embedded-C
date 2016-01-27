#include <stdio.h>
#include <string.h>

void check_input(int matches);
void print_matrix(int row, int col, int matrix[]);

int main(void)
{
    int row, col, number, matches;
    
    printf("count of row --> ");
    matches = scanf("%d", &row);
    check_input(matches);
    
    printf("count of col --> ");
    matches = scanf("%d", &col);
    check_input(matches);
    
    int firstMatrix[row][col];
    int secondMatrix[col][row];
    int productMatrix[row][row];
    
    int i;
    for (i = 0; i < row; i++) 
    {
        int j;
        for (j = 0; j < col; j++)
        {
            printf("matrix1 row%d col%d --> ", i, j);
            matches = scanf("%d", &number);
            check_input(matches);
            firstMatrix[i][j] = number;  
        }
    }
    
    for (i = 0; i < col; i++) 
    {
        int j;
        for (j = 0; j < row; j++)
        {
                printf("matrix2 row%d col%d --> ", i, j);
                matches = scanf("%d", &number);
                check_input(matches);
                secondMatrix[i][j] = number;                                          
        }
    }
    
    memset(productMatrix, 0, sizeof(productMatrix[0][0]) * row * row);
    
    for (i = 0; i < row; i++)
    {
        int j;
        for (j = 0; j < row; j++)
        {
            int k;
            for (k = 0; k < col; k++)
            {
                productMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
            
    printf("first matrix\n");
    print_matrix(row, col, *firstMatrix);
    
    printf("second matrix\n");
    print_matrix(col, row, *secondMatrix);
    
    printf("product matrix\n");
    print_matrix(row, row, *productMatrix);

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

