#include <stdio.h>
#include <math.h>

int main(void)
{
    double x, y, distance, radius = 1.5;
    int matchesX, matchesY, isInsideOutside = 0;
    
    printf("X --> ");
    matchesX = scanf("%lf", &x);
    printf("Y --> ");
    matchesY = scanf("%lf", &y);
    if ((1 != matchesX) || (1 != matchesY))
    {
        printf("Wrong numbers!");
        
        return 1;
    }

    distance = sqrt((x - 1) * (x - 1) + (y - 1) * (y - 1));
    if (distance <= radius && y > 1)
    {
        isInsideOutside = 1;
    }

    printf("Is inside a cirkle and outside of a rectangle --> %s"
            , isInsideOutside ? "yes" : "no");
    
    return 0;
}

