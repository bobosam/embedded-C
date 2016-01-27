#include <stdio.h>

int binary_search(int array[], int first, int last, int searchNumber);
int search_first_index(int array[], int index);

int main(void)
{
    int firstArray[] = {-2, 0, 3, 5, 213, 8582, 239191, 985128};
    int secondArray[] = {0, 1, 2, 3, 4, 5, 6, 6, 7, 8};
    int thirdArray[] = {3, 9, 10, 12, 13, 13, 13, 13};
    int firstSearchNumber = 239191;
    int secondSearchNumber = -2;
    int thirdSearchNumber = 13;
    int firstSize = sizeof(firstArray) / sizeof(int);
    int secondSize = sizeof(secondArray) / sizeof(int);
    int thirdSize = sizeof(thirdArray) / sizeof(int);
    
    printf("first array search --> %d\n",
            binary_search(firstArray, 0, firstSize -1, firstSearchNumber));
    printf("second array search --> %d\n",
            binary_search(secondArray, 0, secondSize - 1, secondSearchNumber));
    printf("third array search --> %d\n",
            binary_search(thirdArray, 0, thirdSize - 1, thirdSearchNumber));

    return 0;
}

int binary_search(int array[], int first, int last, int searchNumber)
{
    if (first > last)
    {
        return -1;
    }
    
    int middle = (first + last) / 2;
    
    if (array[middle] < searchNumber)
    {
        binary_search(array, middle + 1, last, searchNumber);
    }
    else if (array[middle] > searchNumber)
    {
        binary_search(array, first, middle - 1, searchNumber);
    }
    else
    {
        int index = search_first_index(array, middle);

        return index;
    }    
}

int search_first_index(int array[], int index)
{
    if (array[index] > array[index - 1])
    {
        return index;
    }
    
    search_first_index(array, index - 1);
}