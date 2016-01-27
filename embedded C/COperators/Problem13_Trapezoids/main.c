#include <stdio.h>

void checkInput(int matches);

int main(void)
{
    double a, b, h, area;
    int matches;
    
    printf("a --> ");
    matches = scanf("%lf", &a);
    checkInput(matches);
    printf("b --> ");
    matches = scanf("%lf", &b);
    checkInput(matches);
    printf("h --> ");
    matches = scanf("%lf", &h);
    checkInput(matches);
    
    area = ((a + b) * 0.5 * h);
    printf("area --> %.2f", area);
    
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

