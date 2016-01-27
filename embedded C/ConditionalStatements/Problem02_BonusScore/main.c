#include <stdio.h>

int main(void)
{
    int score, matches;
    
    printf("Score --> ");
    matches = scanf("%d", &score);
    if (1 != matches)
    {
        printf("Wrong score!");
        
        return 1;
    }

    switch(score)
    {
        case 1:
        case 2:
        case 3:
            score *= 10;
            break;
        case 4:
        case 5:
        case 6:
            score *= 100;
            break;
        case 7:
        case 8:
        case 9:
            score *= 1000;
            break;
        default :
            printf("invalid score");
            return 0;
    } 
    
    printf("result --> %d", score);

    return 0;
}

