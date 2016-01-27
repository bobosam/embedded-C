#include <stdio.h>
#include <time.h>

void checkInput(int matches);

int main(void)
{
    int n, matches, counter = 1, number;
    char check[1000];
    memset(check, '0',sizeof(check));
    time_t t;
    
    printf("n --> ");
    matches = scanf("%d", &n);
    checkInput(matches);
    
    srand((unsigned) time(&t));
    
    while (counter <= n)
    {
        number = rand() %n + 1;
        if (check[number] == '0')
        {
            check[number] = '1';
            printf("%d ", number);
            counter++;
        }
    }

    return 0;
}

void checkInput(int matches)
{
    if (1 != matches)
    {
        printf("Wrong number");
        exit(1);
    }
}