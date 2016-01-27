#include <stdio.h>

void check_input(int matches);

int main(void)
{
    int dimension, number, matches, scalar;
    
    printf("dimension --> ");
    matches = scanf("%d", &dimension);
    check_input(matches);
    
    int vector[dimension];
    
    printf("scalar --> ");
    matches = scanf("%d", &scalar);
    check_input(matches);
    
    int i;
    for (i = 0; i < dimension; i++)
    {
        printf("member %d --> ", i +1);
        matches = scanf("%d", &number);
        check_input(matches);
        vector[i] = number;
    }
    
    printf("result --> ");
    for (i = 0; i < dimension; i++)
    {
        printf("%d ", vector[i] * scalar);
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

