#include <stdio.h>

 int new_integer();
 int* new_integer_ptr();

int main(void)
{
    int* ptrFunction = new_integer_ptr();
    int valueFunction = new_integer();
    
    printf("number from pointer function --> %d\n", *ptrFunction);
    printf("number from value function --> %d\n", valueFunction);
    printf("number from pointer function again --> %d\n", *ptrFunction);
    printf("number from value function  again --> %d\n", valueFunction);

    return 0;
}

int new_integer()
{
    int number = 155;
    
    return number;
}

int* new_integer_ptr()
{
    int number = 244;
    int* ptr;
    ptr = &number;
    
    return ptr;
}