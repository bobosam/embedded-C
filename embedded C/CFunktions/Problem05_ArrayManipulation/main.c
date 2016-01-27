#include <stdio.h>
#include "array.h"

int main(void)
{
    int arr[] = {13, 14, 15, 16, 2, 4, 8};
    int size = sizeof(arr)/sizeof(int);
    
    int min = arr_min(arr, size);
    printf("min element --> %d\n", min);
    
    int max = arr_max(arr, size);
    printf("max element --> %d\n", max);
    
    arr_clear(arr, size);
    printf("arr-clear --> ");
    int i;
    for (i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    
    int secondArr[] = {5, 24, 8 , 13, 6};
     int sizeSecondArr = sizeof(secondArr)/sizeof(int);
    
    int sum = arr_sum(secondArr, sizeSecondArr);
    printf("\nsum of elements --> %d\n", sum);
    
    double avg = arr_average(secondArr, sizeSecondArr);
    printf("average --> %.2f\n", avg);
    
    int isContains = arr_contains(13, secondArr, sizeSecondArr);
    printf("contains 13 --> %s\n", (isContains ==1) ? "true" : "false");
    
    int mergeSize = size + sizeSecondArr;
    int mergeArr[mergeSize];
    arr_merge(mergeArr, arr, secondArr, size, sizeSecondArr);
    printf("merge arr --> ");
    
    for (i = 0; i < mergeSize; i++)
    {
        printf("%d ", mergeArr[i]);
    }
    
    return 0;
}

