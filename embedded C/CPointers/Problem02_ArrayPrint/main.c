#include <stdio.h>

#define ARRAY_SIZE 5

int main(void)
{
    int array[ARRAY_SIZE] = {1, 2, 3, 4, 5};
    
    printf("[");
    
    int i;
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        int number = *(array + i);
        
        if (i < (ARRAY_SIZE - 1))
        {
            printf("%d, ", number);
        }
        else
        {
            printf("%d]", number);
        }
    }

    return 0;
}

