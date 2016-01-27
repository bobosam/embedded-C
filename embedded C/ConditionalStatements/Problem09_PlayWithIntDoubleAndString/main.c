#include <stdio.h>
#include <string.h>

int main(void)
{
    int intVariable, matches, choice;
    double doubleVariable;
    char string[1000];

    printf("Please choose a type: \n");
    printf("1 --> int\n2 --> double\n3 --> string\n");
    printf("choice --> ");
    matches = scanf("%d", &choice);
    checkInput(matches);
    
    switch(choice)
    {
        case 1:
            printf("Please enter a integer: ");
            matches = scanf("%d", &intVariable);
            checkInput(matches);
            intVariable ++;
            printf("result --> %d", intVariable);
            break;
        case 2:
            printf("Please enter a double: ");
            matches = scanf("%lf", &doubleVariable);
            checkInput(matches);
            doubleVariable ++;
            printf("result --> %.1f", doubleVariable);
            break;
        case 3:
            printf("Please enter a string: ");
            matches = scanf("%999s", &string);
            checkInput(matches);
            strcat(string, "*");
            printf("result --> %s", string);
            break;
        default :
            printf("Wrong choice!");
    }
    
    return 0;
}

void checkInput(int matches)
{
    if (1 != matches)
    {
        printf("Wrong input!");
        exit(1);
    }

}

