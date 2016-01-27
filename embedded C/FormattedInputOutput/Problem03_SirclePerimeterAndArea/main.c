#include <stdio.h>

#define PI 3.14159265358979323846

int main(void)
{
    double radius, perimeter, area;
    
    printf("Enter radius: ");
    scanf("%lf", &radius);
    
    perimeter = 2 * PI * radius;
    area = PI * radius * radius;
            
    printf("|%-10s|%-10s|%-10s|\n", "r", "perimeter", "area");
    printf("|%-10.2g|%-10.2f|%-10.2f|", radius, perimeter, area);

    return 0;
}

