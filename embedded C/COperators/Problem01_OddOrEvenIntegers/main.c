#include <stdio.h>

int main(void)
{
    int number;
    printf("Number for check --> ");
    int matches = scanf("%d", &number);
    
    if (1 != matches)
    {
        printf("Wrong number !");
        return 1;
    }

    printf("Is the %d Odd --> %s", number, number %2 == 0 ? "0" : "1");
    
    return 0;
}

