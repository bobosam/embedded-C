#include <stdio.h>
#include <limits.h>

void check_input(int matches);
void sort_numbers(int array[], int size);
void swap(int* firstIndex, int* secondIndex);

int main(void) 
{
    int firstSize, secondSize, matches, number;
    
    printf("first array size -->");
    matches = scanf("%d", &firstSize);
    check_input(matches);
    printf("second array size -->");
    matches = scanf("%d", &secondSize);
    check_input(matches);
    
    int size = firstSize + secondSize;
    int array[size];
    printf("numbers:\n");
    int i;
    for (i = 0; i < size; i++)
    {
        matches = scanf("%d", &number);
        check_input(matches);
        array[i] = number;
    }
      
    sort_numbers(array, size);

    printf("join numbers --> %d ", array[0]);
    int j;
    for (j = 1; j < size; j++)
    {
        if (array[j] == array[j-1])
        {
            continue;
        }

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
