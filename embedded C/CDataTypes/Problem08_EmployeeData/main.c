#include <stdio.h>
#define BUFFER_SIZE 100

int main(void)
{
    char firstName[BUFFER_SIZE], lastName[BUFFER_SIZE], gender[BUFFER_SIZE];
    char age ;
    long idNumer;
    long long employeeNumber;
    
    printf("Enter first name: ");
    fgets(firstName, BUFFER_SIZE, stdin);
    printf("Enter last name: ");
    fgets(lastName, BUFFER_SIZE, stdin);
    printf("Enter age: ");
    scanf("%d", &age);
    getchar();
    printf("Enter gender m/f: ");
    fgets(gender, BUFFER_SIZE, stdin);
    printf("Enter ID number: ");
    scanf("%ld", &idNumer);
    getchar();
    printf("Enter employee number: ");
    scanf("%lld", &employeeNumber);
    printf("First name: %s", firstName );
    printf("Last name: %s", lastName);
    printf("Age: %d\n", age);
    printf("Gender: %s", gender);
    printf("Personal ID: %ld\n", idNumer);
    printf("Unique Employee number: %lld\n", employeeNumber);
    
    return 0;
}

