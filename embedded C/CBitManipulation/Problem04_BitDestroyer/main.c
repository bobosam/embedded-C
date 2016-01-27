#include <stdio.h>
#include <stdlib.h>

void check_input(int matches);

int main(void)
{
    int number, position, mask, matches, result;
    
    printf("enter number --> ");
    matches = scanf("%d", &number);
    check_input(matches);

    printf("enter position --> ");
    matches = scanf("%d", &position);
    check_input(matches);
    
    mask = ~(1 << position);
    
    result = number & mask;
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
