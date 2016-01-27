#include <stdio.h>

int *func();

int main(void)
{
    int number =10;
    int *mainNumber;
    mainNumber = &number;
    
    int *functionNumber;
    functionNumber = func();
    printf("function number address --> %p number --> %d\n", functionNumber, *functionNumber);
    printf("main number address --> %p number --> %d\n", mainNumber, *mainNumber);
    print();
    printf("function number address --> %p number --> %d", functionNumber, *functionNumber);

    return 0;
}

int *func()
{
    int number = 25;
       
    return &number;
}

void print()
{
    char string[1000] = "function number is lost";
    printf("%s\n", string);
}