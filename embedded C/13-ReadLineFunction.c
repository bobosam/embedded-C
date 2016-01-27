#include <stdio.h>
#include <stdlib.h>

char *get_line(char **bufferPtr, size_t *bufSize)
{
    char *result = *bufferPtr;
    size_t size = *bufSize;
    if (result == NULL)
    {
        result = malloc(INITIAL_BUFFER_LENGTH);
        size = INITIAL_BUFFER_LENGTH;
         if (!result)
            return NULL;
    }
  
    size_t i = 0;
    char ch = getchar();
    while (ch != '\n' && ch != EOF)
    {
        if (i == size - 1)
        {
            char *resized = realloc(result, 2 * size);
            if (!resized)
            {
                return NULL;
            }
            
            result = resized;
            size *= 2;
        }
        
        result[i] = ch;
        i++;
        
        ch = getchar();
    }
    
    result[i] = '\0';
    *bufferPtr = result;
    *bufSize = size;
    
    return result;
}
//////////////////////////////////////////////////////////////////////////////////////////
void resize (char **buffer, size_t *size)
{
    size_t resSize = *size;
    resSize *= 2;
    char *resized = (char *)realloc(*buffer, resSize);
    if (NULL == resized)
    {
        printf("Out of memory!");
        exit(1);
    }
    
    *buffer = resized;
    *size = resSize;
}
/////////////////////////////////////////////////////////////////////////////////////////
void bubble_sort(int array[], int size)
{
    int i, swapped = 1;
    while (swapped)
    {
        // 3, 1, 5, 10, 7, -5
        swapped = 0;
        for (i = 0; i < size - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                // Swap
                int oldValue = array[i];
                array[i] = array[i + 1];
                array[i + 1] = oldValue;
                swapped = 1;
            }
        }  
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int GetBitAtPosition(long long number, int position)
{
    return (number >> position) & 1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void SetBitAtPosition(long long * number, int position, int bit)
{
    if (bit == 0)
    {
        (*number) &= ( ~((long long)1 << position));
    }
    else
    {
        (*number) |= (long long)1 << position;
    }
}
///////////////////////////////////////////////////////////////////////////////
change number sistem
 char digits[32];
    int index = 0;
    while (sum > 0) 
    {
        int digit = sum % key;
        digits[index] = '0' + digit;
        index++;
        sum = sum / key;
    }
    
    digits[index] = '\0';
///////////////////////////////////////////////////////////////////////////////
void change_system(int numbers[], int key, int sum, int *index)
{
    int i = *index;           
    while (sum > 0) 
    {
        numbers[i] = sum %key;
        sum = sum / key;
        i++;
    }
     
     *index = i;
}
