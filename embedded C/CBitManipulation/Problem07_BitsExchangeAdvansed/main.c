#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void check_input(int matches);

int main(void) 
{
    unsigned int number, result, firstGroup, secondGroup;
    int matches, p, q, k;
    
    printf("enter number --> ");
    matches = scanf("%u", &number);
    check_input(matches);
    
    printf("enter start first group p --> ");
    matches = scanf("%d", &p);
    check_input(matches);
    
    printf("enter start second group q --> ");
    matches = scanf("%d", &q);
    check_input(matches);
    
    printf("enter count of bits k --> ");
    matches = scanf("%d", &k);
    check_input(matches);
    
    if (0 > number || 0 > p || 0 > q || 0 > k)
    {
        printf("Out of range!");
        exit(1);
    }
    
    if (32 < (p + k) || 32 < (q + k))
    {
        printf("Out of range!");
        exit(1);
    }


    
    int mask = (int)pow(2, k) - 1;
       
    firstGroup = (number >> p) & mask; 
    secondGroup = (number >> q) & mask;
            
    result = number & (~(mask << q)); //set to 000...
    result = result & (~(mask << p));  //set to 000...
    result = result | (firstGroup << q);
    result = result | (secondGroup << p);
    
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