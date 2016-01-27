#include <stdio.h>
#include <string.h>

int main(void) 
{
    char playCard[3];
    
    printf("character --> ");
    scanf("%2s", &playCard);
    char ten[3] = "10";
    int size = strlen(playCard);
        
    if (size == 1)
    {
        switch(playCard[0])
        {
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case 'J':
            case 'Q':
            case 'K':
            case 'A':
                printf("Valid card sign? --> yes");
                break;
            default:
                printf("Valid card sign? --> no");
        }
    }
    else if(strcmp(ten, playCard) == 0)
    {
        printf("Valid card sign? --> yes");
    }
    else
    {
        printf("Valid card sign? --> no");
    }
    
    return 0;
}

