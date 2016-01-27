#include <stdio.h>
#include <stdlib.h>

void check_input(int matches);

int main(void) 
{
    int n, step, number, matches;
    int position = 1;
    
    matches = scanf("%d", &n);
    check_input(matches);
    
    matches = scanf("%d", &step);
    check_input(matches);
    
    int i;
    for (i = 0; i < n; i++) 
    {
        matches = scanf("%d", &number);
        while (8 > position)
        {
            int mask = 1 << (7 - position);
            number = number | mask;
            position += step;
        }
        
        position = position - 8;
        printf("%d\n", number);
    }

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

