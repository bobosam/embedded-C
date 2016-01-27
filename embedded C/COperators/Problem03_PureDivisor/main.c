#include <stdio.h>

int main(void)
{
    int number;
    
    printf("Enter the number for check --> ");
    int matches = scanf("%d", &number);
    if (1 != matches)
    {
        printf("Wrong number !");
        return 1;
    }
    
    int check = (0 == number %9) || (0 == number %11) || (0 == number %13);
    
    printf("Is the %d divided by 9, 11 or 13 --> %d", number, check);

    return 0;
}

