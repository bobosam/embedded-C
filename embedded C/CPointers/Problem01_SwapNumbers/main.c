#include <stdio.h>

void swap(int *firstNumber, int *secondNumber);
void check_input(int matches);

int main(void)
{
    int a, b, matches;
    
    printf("number a --> ");
    matches = scanf("%d", &a);
    check_input(matches);
    
    printf("number b --> ");
    matches = scanf("%d", &b);
    check_input(matches);
    
    swap(&a, &b);
    
    printf("number a --> %d\nnumber b --> %d", a, b);

    return 0;
}

void swap(int *firstNumber, int *secondNumber)
{
    int tmp = *firstNumber;
    *firstNumber = *secondNumber;
    *secondNumber = tmp;
}

void check_input(int matches)
{
    if (1 != matches)
    {
        printf("Wrong number!");
        exit(1);
    }
}

