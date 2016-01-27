#include <stdio.h>

int main(void)
{
    double weight, weightOnTheMoon;
    
    printf("Enter the weight --> ");
    int matches = scanf("%lf", &weight);
    
    if (1 != matches)
    {
        printf("Wrong weight!");
        
        return 1;
    }

    weightOnTheMoon = weight * 0.17;
    
    printf("Weight %g on the moon is --> %.3f", weight, weightOnTheMoon);

    return 0;
}

