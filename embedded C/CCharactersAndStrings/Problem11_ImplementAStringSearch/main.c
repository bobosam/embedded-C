#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str_search(char *string, char *substring);

int main(void)
{
    int search;
    
    search = str_search("SoftUni", "Soft");
    printf("search Soft --> %d\n", search);
    
    search = str_search("Hard Rock", "Rock");
    printf("search Rock --> %d\n", search);
     
    search = str_search("Ananas", "nasa");
    printf("search nasa --> %d", search);

    return 0;
}

int str_search(char *string, char *substring)
{
    size_t stringSize = strlen(string);
    size_t substringSize = strlen(substring);
    int check = 0;
   
    if (substringSize > stringSize)
    {
       return 0;
    }
    
    size_t i;
    for (i = 0; i < stringSize; i++)
    {
        if (string[i] == substring[0])
        {
            int j;
            for (j = 1; j < substringSize; j++) 
            {
                if (string[i + j] != substring[j])
                {
                    check = 1;
                    break;
                }
            }
            
            if (0 == check)
            {
                return 1;
            }
            
            check = 0;
        }
    }

    return 0;
}

