#include <stdio.h>
#include <stdlib.h>

void check_input(int matches);

int main(void) 
{
    unsigned int number, result, firstGroup, secondGroup;
    int matches;
    
    printf("enter number --> ");
    matches = scanf("%u", &number);
    check_input(matches);
       
    firstGroup = (number >> 3) & 7;
    secondGroup = (number >> 24) & 7;
        
    result = number & (~(7 << 24));     //set to 000
    result = result & (~(7 << 3));      //set to 000
    result = result | (firstGroup << 24);
    result = result | (secondGroup << 3);
    
    printf("result --> %u", result);
    
    return 0;
}

void check_input(int matches)
{
    if (1 != matches)
    {
        printf("Wrong number!");
        exit(1);
    }
}