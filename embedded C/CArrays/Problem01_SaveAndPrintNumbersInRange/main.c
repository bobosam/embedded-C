#include <stdio.h>

void checkInput(int matches);

int main(void)
{
    int size, matches, number;
    
    printf("Count of numbers --> ");
    matches = scanf("%d", &size);
    checkInput(matches);
    
    int array[size];
    
    printf("Numbers --> ");
    
    int i;
    for (i = 0; i < size; i++)
    {
        matches = scanf("%d", &number);
        checkInput(matches);
        array[i] = number;
    }

    printf("Numbers from array --> ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }


    return 0;
}

void checkInput(int matches)
{
    if (1 != matches)
    {
        printf("Wrong number!");
        exit(1);
    }

}

