#include <stdio.h>
#include <limits.h>

int searchForLarger(int* arr, int size);

int main(void)
{
    int sequenceOne[] = { 1, 3, 4, 5, 1, 0, 5 };
    int sequenceTwo[] = { 1, 2, 3, 4, 5, 6, 6 };
    int sequenceThree[] = { 1, 1, 1 };
    
    int sizeOne = sizeof(sequenceOne) / sizeof(int);
    int sizeTwo = sizeof(sequenceTwo) / sizeof(int);
    int sizeThree = sizeof(sequenceThree) / sizeof(int);
    
    int indexOne = searchForLarger(sequenceOne, sizeOne);
    int indexTwo = searchForLarger(sequenceTwo, sizeTwo);
    int indexThree = searchForLarger(sequenceThree, sizeThree);
    
    printf("index one --> %d\nindex two --> %d\nindex three --> %d",
            indexOne, indexTwo, indexThree);

    return 0;
}

int searchForLarger(int* arr, int size)
{
    int i;
    for (i = 1; i < size - 1; i++)
    {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
        {
            return i;
        }
    }
    
    return -1;
}