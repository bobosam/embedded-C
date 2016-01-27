#include <stdio.h>

int main(void) 
{
    char firstName[20], secondName[20];
    printf("Enter first name: ");
    scanf("%19s", firstName);
    printf("Enter second name: ");
    scanf("%19s", secondName);
    
    printf("%s %s", firstName, secondName);
    
    return 0;
}

