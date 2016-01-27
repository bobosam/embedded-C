#include <stdio.h>
#include <limits.h>

void check_input(int matches);
void sort_numbers(int array[], int size);
void swap(int* firstIndex, int* secondIndex);

int main(void) 
{
    int size, matches, number;
    
    printf("count of numbers --> ");
    matches = scanf("%d", &size);
    check_input(matches);
    int array[size];
    int i;
    for (i = 0; i < size; i++)
    {
        printf("number %d --> ", i+1);
        matches = scanf("%d", &number);
        check_input(matches);
        array[i] = number;
    }
    
    sort_numbers(array, size);

    printf("sorting numbers --> ");
    int j;
    for (j = 0; j < size; j++)
    {
        printf("%d ", array[j]);
    }

    return 0;
}

void sort_numbers(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        int min = INT_MAX;
        int j;
        for (j = size - (size - i); j < size; j++)
        {
            if (array[j] < array[i])
            {
                swap(&array[i], &array[j]);
            }
        }
    }
}

void swap(int* firstIndex, int* secondIndex)
{
    int tmp = *firstIndex;
    *firstIndex = *secondIndex;
    *secondIndex = tmp;  
}

void check_input(int matches)
{
    if (1 != matches)
    {
        printf("Wrong number!");
        exit(1);
    }
}