#include <stdio.h>
#include <stdlib.h>

int **matrix_create(int rowsCount, int colsCount)
{
    // 4-byte pointers x rowsCount
    int **rows = calloc(rowsCount, sizeof(int*));
    if(NULL == rows)
    {
        exit(1);
    }
    
    int i = 0;
    while (i < rowsCount)
    {
        rows[i] = calloc(colsCount, sizeof(int));
        if (NULL == rows[i])
        {
            exit(1);
        }

        i++;
    }
    
    return rows;
}

int main() 
{
    // Declare
    int size = 3;
    int **matrix = matrix_create(size, size);
    
    // Modify
    matrix[0][0] = 3;
    matrix[0][2] = -2;
    matrix[1][2] = 4;
    matrix[2][1] = 1;
    
    int row;
    for (row = 0; row < size; row++)
    {
        int col;
        for (col = 0; col < size; col++)
        {
            printf("%d ", matrix[row][col]);
        }
        
        printf("\n");
    }
    
    int i;
    for (i = 0; i < size; i++)
    {
        free(matrix[i]);
    }

    // Free
    free(matrix);
    
    return (EXIT_SUCCESS);
}
