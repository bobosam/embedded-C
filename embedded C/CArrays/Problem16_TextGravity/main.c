#include <stdio.h>
#include <string.h>

void check_input(int matches);

#define BUFFER_SIZE 1001

int main(void)
{
    char textLine[BUFFER_SIZE];
    int lineLenght, rowMatrix, col = 0, row = 0, matches;
    
    matches = scanf("%d", &lineLenght);
    check_input(matches);
    getchar();
    fgets(textLine, BUFFER_SIZE, stdin);
    textLine[strlen(textLine) - 1] = '\0';
    rowMatrix = strlen(textLine) / lineLenght;
    if (0 != strlen(textLine) %lineLenght) 
    {
        rowMatrix++;
    }
    
    char matrix[rowMatrix][lineLenght];
    memset(matrix, ' ', sizeof(matrix[0][0]) *rowMatrix * lineLenght);
    
    int i;
    for (i = 0; i < strlen(textLine); i++)
    {
        matrix[row][col] = textLine[i];
        col++;
        if (col == lineLenght)
        {
            row++;
            col = 0;
        }
    }
    
    for (i = rowMatrix - 1; i >= 0; i--)
    { 
        int j;
        for (j = lineLenght -1; j >= 0; j--) 
        {
            if (' ' == matrix[i][j])
            {
                int counter = i-1;
                while (' ' == matrix[i][j] && 0 <= counter)
                {
                    matrix[i][j] = matrix[counter][j];
                    matrix[counter][j] = ' ';
                    counter--;
                }
            }
        }
    }

    
    int j;
    for (j = 0; j < rowMatrix; j++)
    {
        printf("|");
        int k;
        for (k = 0; k < lineLenght; k++)
        {
            printf("%c", matrix[j][k]);

        }

        printf("|\n");
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