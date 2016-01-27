#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void memory_dump(void *ptr, int size, int rowLenght);

int main(void)
{
    char *text = "I love to break free";
    int array[] = {7, 3, 2, 10, -5};
    
    printf("passing int array:\n");
    memory_dump(array, sizeof(array), 4);
    printf("\n\npassing char pointer:\n");
    memory_dump(text, strlen(text) + 1, 5);

    return 0;
}

void memory_dump(void *ptr, int size, int rowLenght)
{
    int counter = 0;
    char *charPtr = ptr;
    
    printf("%p   ", charPtr);
    
    int i;
    for (i = 0; i < size; i++) 
    {
        printf("%02x ", (*(charPtr + i)) & 0xFFU );
        counter++;
        
        if (0 == counter %rowLenght && i < size - 1)
        {
            printf("\n%p   ", charPtr + i);
            counter = 0;
        }
    }
}

