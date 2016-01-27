#include <stdio.h>

void check_input(int matches);
void last_digit_as_word(int input);

int main(void)
{
    int input, matches;
        
    printf("input --> ");
    matches = scanf("%d", &input);
    check_input(matches);
    
    last_digit_as_word(input);
    
    return 0;
}

void last_digit_as_word(int input)
{
    int lastDigit;
    lastDigit = input % 10;
    
    switch(lastDigit)
    {
        case 0: printf("Last digit as word --> zero");break;
        case 1: printf("Last digit as word --> one");break;
        case 2: printf("Last digit as word --> two");break;
        case 3: printf("Last digit as word --> three");break;
        case 4: printf("Last digit as word --> four");break;
        case 5: printf("Last digit as word --> five");break;
        case 6: printf("Last digit as word --> six");break;
        case 7: printf("Last digit as word --> seven");break;
        case 8: printf("Last digit as word --> eight");break;
        case 9: printf("Last digit as word --> nine");break;
    }
}

void check_input(int matches)
{
    if (1 != matches)
    {
        printf("Wrong number");
        exit(1);
    }
}

