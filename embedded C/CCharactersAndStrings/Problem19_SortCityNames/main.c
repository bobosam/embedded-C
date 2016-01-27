#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

void check_input(int matches);
void sort_cities(int count, char cities[][MAX_NAME_LENGTH]);
void print_cities(int count, char cities[][MAX_NAME_LENGTH]);

int main(void)
{
    int count, matches;
    
    printf("count of cities --> ");
    matches = scanf("%d", &count);
    check_input(matches);
    getchar();
    
    char cities[count][MAX_NAME_LENGTH];
    
    int i;
    for (i = 0; i < count; i++)
    {
        fgets(cities[i], MAX_NAME_LENGTH, stdin);
        int length = strlen(cities[i]);
        if ('\n' == cities[i][length - 1])
        {
            cities[i][length - 1] = '\0';
        }
    }
    
    sort_cities(count, cities);   
    printf("\nsort:\n");
    print_cities(count, cities);
   
    return 0;
}

void check_input(int matches)
{
    if (1 != matches)
    {
        printf("Wrong input!");
        exit(1);
    }
}

void sort_cities(int count, char cities[][MAX_NAME_LENGTH])
{
    char min[MAX_NAME_LENGTH];
    char tmp[MAX_NAME_LENGTH];
    int i;    
    for (i = 0; i < count; i++)
    {
        strcpy(min, cities[i]);
        int j;
        for (j = i + 1; j < count; j++)
        {
            if (0 < strcmp(min, cities[j]))
            {
                strcpy(tmp, min);
                strcpy(min, cities[j]);
                strcpy(cities[j], tmp);
            }
        }
        
        strcpy(cities[i], min);
    }
}

void print_cities(int count, char cities[][MAX_NAME_LENGTH])
{
    int i;
    for (i = 0; i < count; i++)
    {
        printf("%s\n", cities[i]);
    }
}
