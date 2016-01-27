#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 4

typedef struct tag_client
{
    char name[50];
    int age;
    double account_balance;
}sClient;

typedef int(*pfComparator)(sClient*, sClient*);

int compare_by_age(sClient* a, sClient* b);
int compare_by_balance(sClient* a, sClient* b);
int compare_by_name(sClient* a,sClient* b);
void swap(sClient* a, sClient* b);
void sort(sClient* array, size_t lenght, pfComparator pCompareFunc);

int main(void)
{
    sClient clients[] = {
        {"Ivan", 25, 254.54},
        {"Stefan", 33, 472.00},
        {"Ogi", 42, 578.25},
        {"Stamat", 27, 548.15}
        };
        
    sort(clients, SIZE, &compare_by_age);
    printf("Sort by age:\n");
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf("Name --> %s age --> %d\n", clients[i].name, clients[i].age);
    }
    
    sort(clients, SIZE, &compare_by_balance);
    printf("\nSort by balance:\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("Name --> %s balance --> %.2f\n", clients[i].name, clients[i].account_balance);
    }

    sort(clients, SIZE, &compare_by_name);
    printf("\nSort by name:\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("Name --> %s\n", clients[i].name);
    }

    
    return 0;
}

void sort(sClient* array, size_t lenght, pfComparator pCompareFunc)
{
    int isSwaped = 1;
    while(0 != isSwaped)
    {
        isSwaped = 0;
        int i;
        for (i = 0; i < lenght-1; i++)
        {
            if (pCompareFunc(&array[i], &array[i + 1]))
            {
                swap(&array[i], &array[i + 1]);
                isSwaped = 1;
            }
        }
    }
}

void swap(sClient* a, sClient* b)
{
    sClient tmp;
    
    memcpy(&tmp, a, sizeof(sClient));
    memcpy(a, b, sizeof(sClient));
    memcpy(b, &tmp, sizeof(sClient));
}

int compare_by_age(sClient* a, sClient* b)
{
    return a->age > b->age;
}

int compare_by_balance(sClient* a, sClient* b)
{
    return a->account_balance > b->account_balance;
}

int compare_by_name(sClient* a,sClient* b)
{
    int compare = strcmp(a->name, b->name);
    
    return  (compare > 0) ? 1 : 0 ;
}
