#include <stdio.h>

int main(void)
{
    int number;
    char *isDivide;
    
    printf("Enter integer number: ");
    int matches = scanf("%d", &number);
    if (1 != matches)
    {
        printf("Wrong number!");
        
        return 1;
    }
    
    isDivide = ((number %35 == 0) && (0 != number)) ? "1" : "0";
    
    printf("Is divided by 7 and 5? --> %s", isDivide);

    return 0;
}

