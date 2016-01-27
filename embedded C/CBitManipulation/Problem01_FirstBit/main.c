#include <stdio.h>
#include <stdlib.h>

void check_input(int matches);

int main(void)
{
    int number, matches, position;
    
    printf("enter number --> ");
    matches = scanf("%d", &number);
    check_input(matches);
    
    printf("enter bit position --> ");
    matches = scanf("%d", &position);
    check_input(matches);
    
    int result = (number >> position) & 1;
    
    printf("bit in position %d --> %d", position, result);

    return 0;
}

void check_input(int matches)
{
    if (1 != matches)
    {
        printf("Wrong input!");
        exit(1);
    }

}