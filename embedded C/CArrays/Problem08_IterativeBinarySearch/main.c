#include <stdio.h>

int binary_search(int array[], int size, int searchNumber);

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
            binary_search(firstArray, firstSize, firstSearchNumber));
    printf("second array search --> %d\n",
            binary_search(secondArray, secondSize, secondSearchNumber));
    printf("third array search --> %d\n",
            binary_search(thirdArray, thirdSize, thirdSearchNumber));

    return 0;
}

int binary_search(int array[], int size, int searchNumber)
{
    int first = 0;
    int last = size - 1;
    int middle = (first + last) / 2;
    
    while (first <= last)
    {
        if (array[middle] < searchNumber)
        {
            first = middle + 1;
        }
        else if (array[middle] > searchNumber)
        {
            last = middle - 1;
        }
        else
        {
            while (array[middle - 1] == array[middle])
            {
                middle = middle - 1;
            }

            return middle;
        }
        
        middle = (first + last) / 2;
    }
    
    if (first > last)
    {
        return -1;
    }
}

