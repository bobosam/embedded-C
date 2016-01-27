#include <stdio.h>
#include <stdlib.h>

void check_input(int matches);

int main(void)
{
    int number, result, matches, position, maskOne, maskZero, value;
    
    printf("enter number --> ");
    matches = scanf("%d", &number);
    check_input(matches);
    
    printf("enter position --> ");
    matches = scanf("%d", &position);
    check_input(matches);
    
    printf("enter value --> ");
    matches = scanf("%d", &value);
    check_input(matches);
    
    maskZero = ~(1 << position);
    maskOne = 1 << position;
    
    switch (value)
    {
        case 0: result = number & maskZero; break;
        case 1: result = number | maskOne; break;
        default: printf("Wrong value!"); exit(1);
    }

    printf("result --> %d", result);
    
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
