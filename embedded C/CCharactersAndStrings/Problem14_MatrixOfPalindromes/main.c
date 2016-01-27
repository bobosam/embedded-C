#include <stdio.h>
#include <stdlib.h>

void check_input(int matches);

int main(void)
{
    int matches, row, col;
    char string[4];
    
    printf("enter row --> ");
    matches = scanf("%d", &row);
    check_input(matches);
    
    printf("enter col --> ");
    matches = scanf("%d", &col);
    check_input(matches);
    
    int i;
    for (i = 0; i < row; i++)
    {
        int j;
        for (j = 0; j < col; j++)
        {
            string[0] = 'a' + i;
            string[1] = 'a' + i + j;
            string[2] = 'a' + i;
            string[3] = '\0';
            printf("%s ", string);
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
        exit(-1);
    }
}

