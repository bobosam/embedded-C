#include <stdio.h>

int main(void) 
{
    int n, matches, result = 0, delimeter = 5;
    
    printf("n --> ");
    matches = scanf("%d" , &n);
    checkInput(matches);
    
    while (1 < n / delimeter)
    {
        result += n / delimeter;
        delimeter *= 5;
    }

    printf("trailing zeroes of n! --> %d", result);

    return 0;
}

void checkInput(int matches)
{
    if (1 != matches)
    {
        printf("Wrong number!");
        exit(1);
    }
}

