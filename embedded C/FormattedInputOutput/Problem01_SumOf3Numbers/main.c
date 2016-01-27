#include <stdio.h>

int main(void)
{
    double a, b, c, sum;
    
    printf("Enter A: ");
    scanf("%lf", &a);
    printf("Enter B: ");
    scanf("%lf", &b);
    printf("Enter C: ");
    scanf("%lf", &c);
    
    printf("|%-10s|%-10s|%-10s|%-10s\n", "a", "b", "c", "sum");
    printf("|%-10g|%-10g|%-10g|%-10.2f\n", a, b, c, a + b+ c);

    return 0;
}

