#include <stdio.h>

int main(void)
{
    int temp, a, b;
    a = 5;
    b = 10; 
     printf("a = %d \nb = %d\n\n", a, b);
      
    temp = a;
    a = b;
    b = temp;
    
     printf("a = %d \nb = %d\n", a, b);

    return 0;
}

