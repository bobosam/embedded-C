#include <limits.h>
#include "array.h"

int arr_min(int* arr, int size)
{
    int min = INT_MAX;
           
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    return min;
}

int arr_max(int* arr, int size)
{
    int max = INT_MIN;
            
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

void arr_clear(int* arr, int size)
{   
    int i;
    for (i = 0; i < size; i++)
    {
        arr[i] = 0;
    }
}

double arr_average(int* arr, int size)
{
    int sum = 0;
    double avg;
         
    sum = arr_sum(arr, size);    
    avg = (double)sum / size;
    
    return avg;
}

int arr_sum(int* arr, int size)
{
    int sum= 0;
         
    int i;
    for (i = 0; i < size; i++)
    {
      sum += arr[i];  
    }

    return sum;
}

int arr_contains(int number, int* arr, int size)
{
    int isContains = 0;
         
    int i;
    for (i = 0; i < size; i++) 
    {
        if (number == arr[i])
        {
            isContains = 1;
            
            return isContains;
        }
    }

    return isContains;
}

void arr_merge(int* mergeArr, int* firstArr, int* secondArr, int firstSize, int secondSize)
{
    int mergeSize = firstSize + secondSize;
    
    int i;
    for (i = 0; i < mergeSize; i++)
    {
        if (i < firstSize)
        {
            mergeArr[i] = firstArr[i];
        }
        else
        {
            mergeArr[i] = secondArr[i - firstSize];
        }
    }
}