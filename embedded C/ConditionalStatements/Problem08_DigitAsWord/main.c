#include <stdio.h>
#include <string.h>

int main(void)
{
    int matches;
    char digit[3];
    printf("digit --> ");
    matches = scanf("%2s", digit);
    checkInput(matches);
    
    if (1 != strlen(digit)) 
    {
        printf("not a digit");
        exit(1);
    }
    
    switch (digit[0])
    {
        case '0':
            printf("result --> zero");
            break;
        case '1':
            printf("result --> one");
            break;
        case '2':
            printf("result --> two");
            break;
        case '3':
            printf("result --> three");
            break;
        case '4':
            printf("result --> four");
            break;
        case '5':
            printf("result --> five");
            break;
        case '6':
            printf("result --> six");
            break;
        case '7':
            printf("result --> seven");
            break;
        case '8':
            printf("result --> eight");
            break;
        case '9':
            printf("result --> nine");
            break;
        default:
             printf("not a digit");
    }

    return 0;
}

void checkInput(int matches)
{
    if (1 != matches)
    {
        printf("not a digit");
        exit(1);
    }

}
