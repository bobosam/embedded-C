#include <stdio.h>
#include <math.h>

void checkInput(int matches);

int main(void)
{
    int matches;
    double distance, x, y;
    char *isInside;
    
    printf("X --> ");
    matches = scanf("%lf", &x);
    checkInput(matches);
    printf("Y --> ");
    matches = scanf("%lf", &y);
    checkInput(matches);
           
    distance = sqrt((x  * x) + (y * y));
    isInside = (2 >= distance) ? "Yes" : "No";
    
    printf("Inside --> %s", isInside);


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


