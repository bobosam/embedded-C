#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 50

int main()
{
    int counter = 1, oddProduct = 1, evenProduct = 1;
    char line[BUFFER_SIZE];
    fgets(line, BUFFER_SIZE, stdin);
    int lenght = strlen(line);
    if (line[lenght - 1] == '\n')
    {
         line[lenght - 1] = '\0';
    }

    char *token = strtok(line, " ");
    while (token != NULL)
    {
        if (0 == counter %2)
        {
            evenProduct *= atoi(token);
        }
        else
        {
            oddProduct *= atoi(token);
        }
        
        token = strtok(NULL, " ");
        counter++;
    }

    if (oddProduct == evenProduct)
    {
        printf("yes\nproduct = %d", oddProduct);
    }
    else
    {
        printf("no\nodd_product = %d\neven_product = %d", oddProduct, evenProduct);
    }

    
   return(0);
}