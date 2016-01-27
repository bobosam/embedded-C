#include <stdio.h>

int main(void)
{
    int number, matches, firstMember, secondMember, thirdMember;
    int matrix[2][3];
    
    int i;
    for (i = 0; i < 2; i++)
    {
        int j;
        for (j = 0; j < 3; j++) 
        {
            printf("vector %d member %d --> ", i+1, j+1);
            matches = scanf("%d", &number);
            check_input(matches);
            matrix[i][j] = number;
        }
    }

    firstMember = matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1];
    secondMember = matrix[0][2] * matrix[1][0] - matrix[0][0] * matrix[1][2];
    thirdMember = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    
    printf("cross product --> [%d, %d, %d]", firstMember, secondMember, thirdMember);

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

