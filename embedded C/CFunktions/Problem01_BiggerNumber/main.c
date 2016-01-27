#include <stdio.h>

int get_max(int firstNumber, int secondNumber);
void check_input(int matches);

int main(void) 
{
    int firstNumber, secondNumber, maxNumber, matches;
    
    printf("first number --> ");
    matches = scanf("%d", &firstNumber);
    check_input(matches);
    printf("second number --> ");
    matches = scanf("%d", &secondNumber);
    check_input(matches);
    
    maxNumber = get_max(firstNumber, secondNumber);
    
    printf("max number --> %d", maxNumber);
    

    return 0;
}

int get_max(int firstNumber, int secondNumber)
{
    if (firstNumber >= secondNumber)
    {
        return firstNumber;
    }

    return secondNumber;
}

void check_input(int matches)
{
    if (1 != matches)
    {
        printf("Wrong number");
        exit(1);
    }
}