#include <stdio.h>

int main(void)
{
    int number;
        
    printf("Enter number for check --> ");
    int matches = scanf("%d", &number);
    
    if (1 != matches)
    {
        printf("Wrong number !");
        return 1;
    }
    
    char check = ((0 != number %2) && (20 < number)) ? 1 : 0;
    printf("Is %d Odd and greater then 20 --> %d", number, check);

    return 0;
}

