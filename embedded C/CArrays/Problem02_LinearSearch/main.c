#include <stdio.h>

void check_input(int matches);
int linear_search(int array[], int size, int searchNumber);

int main(void)
{
    int size, number, matches, searchNumber;
    
    printf("count of numbers --> ");
    matches = scanf("%d", &size);
    check_input(matches);
    
    int array[size];  
    printf("line numbers --> ");
    
    int i;
    for (i = 0; i < size; i++)
    {
        matches = scanf("%d", &number);
        check_input(matches);
        array[i] = number;
    }

    printf("number for search --> ");
    matches = scanf("%d", &searchNumber);
    check_input(matches);
    
    int result = linear_search(array, size, searchNumber);
    
    printf("result --> %s", result ? "yes" : "no");

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

int linear_search(int array[], int size, int searchNumber)
{
    int i;
    for (i = 0; i < size; i++) 
    {
        if (searchNumber == array[i])
        {
            return 1;
        }
    }
    
    return 0;
}