#include <stdio.h>

int main(void) 
{
    double width, height, perimeter, area;
    int firstMatches, secondMatches;
    
    printf("Please enter width --> ");
    firstMatches = scanf("%lf", &width);
    printf("Please enter height --> ");
    secondMatches = scanf("%lf", &height);
    
    if (1 != firstMatches || 1 != secondMatches)
    {
        printf("Wrong numbers!");
        
        return 1;
    }
    
    perimeter = 2 * (width + height);
    area = width * height;
    
    printf("perimeter --> %g\narea --> %.1f", perimeter, area);

    return 0;
}

