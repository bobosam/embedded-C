#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

int main(void)
{
    char companyName[BUFFER_SIZE], companyAddress[BUFFER_SIZE], phoneNumber[BUFFER_SIZE];
    char faxNumber[BUFFER_SIZE], webSite[BUFFER_SIZE], managerFirstName[BUFFER_SIZE];
    char managerLastName[BUFFER_SIZE], managerPhone[BUFFER_SIZE];
    int age;
    
    printf("Company name: ");
    fgets(companyName, BUFFER_SIZE, stdin);
    printf("Company address: ");
    fgets(companyAddress, BUFFER_SIZE, stdin);
    printf("Phone number: ");
    fgets(phoneNumber, BUFFER_SIZE, stdin);
    printf("Fax number: ");
    fgets(faxNumber, BUFFER_SIZE, stdin);
    printf("Web site: ");
    fgets(webSite, BUFFER_SIZE, stdin);
    printf("Manager first name: ");
    scanf("%100s", managerFirstName);
    printf("Manager last name: ");
    scanf("%100s", managerLastName);
    printf("Manager age: ");
    scanf("%d", &age);
    printf("Manager phone: ");
    scanf("%s", managerPhone);
    
    printf("\n\n%s", companyName);
    printf("Address: %s", companyAddress);
    printf("Tel. %s", phoneNumber);
    printf("Fax: %s\n", strcmp(faxNumber, "")? "(no fax)": faxNumber);
    printf("Web site: %s", webSite);
    printf("Manager: %s %s (age:%d, tel. %s)", managerFirstName, managerLastName, age, managerPhone);

    return 0;
}

