#include <stdio.h>
#include <string.h>

void checkInput(int matches);

int main(void)
{
    int hour, minute, matches, beerTime = 1;
    char designator[3];
    
    printf("time --> ");
    matches = scanf("%d:%d %2s", &hour, & minute, & designator);
    checkInput(matches);
    
    if (!strcmp(designator, "PM") && 0 == hour)
    {
        beerTime = 0;
    }
      
    if (!strcmp(designator, "AM") && 3 <= hour)
    {
        beerTime = 0;
    }

    printf("%s", beerTime == 0 ? "non-beer time" : "beer time");

    
    return 0;
}

void checkInput(int matches)
{
    if (3 != matches)
    {
        printf("Wrong time!");
        exit(1);
    }
}
