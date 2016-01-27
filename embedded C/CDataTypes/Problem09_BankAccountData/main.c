#include <stdio.h>
#define BUFFER_SIZE 100

int main(void)
{
    char firstName[BUFFER_SIZE], middleName[BUFFER_SIZE], lastName[BUFFER_SIZE];
    char bankName[BUFFER_SIZE], iban[BUFFER_SIZE] ;
    long double balance;
    int firstCard, secondCard, thirdCard;
    
    printf("Enter first name: ");
    fgets(firstName, BUFFER_SIZE, stdin);
    printf("Enter middle name: ");
    fgets(middleName, BUFFER_SIZE, stdin);
    printf("Enter last name: ");
    fgets(lastName, BUFFER_SIZE, stdin);
    printf("Enter amount of money: ");
    scanf("%llf", &balance);
    getchar();
    printf("Enter bank name: ");
    fgets(bankName, BUFFER_SIZE, stdin);
    printf("Enter IBAN: ");
    fgets(iban, BUFFER_SIZE, stdin);
    printf("Enter first credit card number: ");
    scanf("%d", &firstCard);
    printf("Enter second credit card number: ");
    scanf("%d", &secondCard);
    printf("Enter third credit card number: ");
    scanf("%d", &thirdCard);
    
    printf("\nFirst name: %s", firstName );
    printf("Middle name: %s", middleName );
    printf("Last name: %s", lastName);
    printf("Amount of money: %.2Lf\n", balance);
    printf("Bank name: %s", bankName);
    printf("IBAN: %s", iban);
    printf("First credit card number: %d\n", firstCard);
    printf("Second credit card number: %d\n", secondCard);
    printf("Third credit card number: %d\n", thirdCard);
    
    return 0;
}
