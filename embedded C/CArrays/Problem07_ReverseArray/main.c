#include <stdio.h>

void check_input(int matches);

int main(void)
{
    int size, number, matches;
    
    printf("count of numbers --> ");
    matches = scanf("%d", &size);
    check_input(matches);
    int array[size];
    
    int i;
    for (i = 0; i < size; i++)
    {
        printf("number %d --> ", i + 1);
        matches = scanf("%d", &number);
        check_input(matches);
        array[i] = number;
    }
    
    printf("reverse --> ");
    int j;
    for (j = size - 1; j >= 0; j--)
    {
        printf("%d ", array[j]);
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

