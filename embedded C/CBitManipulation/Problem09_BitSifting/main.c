#include <stdio.h>
#include <stdlib.h>

void check_input(int matches);

int main(void)
{
    unsigned long long number, mask = 0, sifting;
    int n, matches, counter = 0, digit;
    
    matches = scanf("%llu", &number);
    check_input(matches);
    
    matches = scanf("%d", &n);
    check_input(matches);
    
    int i;
    for (i = 0; i < n; i++)
    {
        matches = scanf("%llu", &sifting);
        check_input(matches);
        
        mask = mask | sifting;
    }

    mask = ~mask;
    number = number & mask;
    
    int j;
    for (j = 0; j < 64; j++)
    {
        digit = (number >> j) & 1;
        counter += digit;
    }

    printf("%d", counter);
    
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

