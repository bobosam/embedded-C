#include <stdio.h>

int main(void)
{
    double doubleNumber = 34.567839023;
    float floatNumber = 12.345;
    double secondDoubleNumber = 8923.1234857;
    float secondFloatNumber = 3456.091;
    
    printf("%.*f\n%.*f\n%.*f\n%.*f", 9, doubleNumber, 3, floatNumber, 7, secondDoubleNumber, 3, secondFloatNumber);

    return 0;
}

