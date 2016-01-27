#include <stdio.h>

int main(void) 
{
    int number, matches;
    char *check;
    
    printf("Please enter a number for check --> ");
    matches = scanf("%d", &number);
    if (1 != matches)
    {
        printf("Wrong number!");
        return 1;
    }
    
    number = (double)number * 0.01;
    check = (7 == number %10)? "true" : "false";
    
    printf("Is third digit is 7 --> %s", check);

    return 0;
}

