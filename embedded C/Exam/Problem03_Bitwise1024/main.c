#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COMMAND_SIZE 9
#define SIZE_NUMBERS 64
int main(void)
{
    int count = 0;
    unsigned long long number = 0;
       
    scanf("%d", &count);
     unsigned long long numbers[count];
    
    int i;
    for (i = 0; i < count; i++)
    {
        scanf("%llu", &number);
        numbers[i] = number;
    }
    
    char commandLine[COMMAND_SIZE];
    int position;
    char command[COMMAND_SIZE];
    
    getchar();
    
    fgets(commandLine, COMMAND_SIZE, stdin);   
    sscanf(commandLine, "%s %d", command, &position);   
    
    while (0 != strcmp("end", command))
    {
        int i;
        for (i = 0; i < count; i++)
        {
            int counter = 0;
            if (0 == strcmp("left", command))
            {
                int j;
                for (j = position; j < SIZE_NUMBERS; j++)
                {
                    counter += (numbers[i] >> j) & (long long)1;
                }
                                                
                for (j = position; j <  SIZE_NUMBERS; j++)
                {
                    numbers[i] = numbers[i] & (~((long long)1 << j ));
                }
                                               
                for (j = SIZE_NUMBERS - counter; j < SIZE_NUMBERS; j++)
                {
                    numbers[i] = numbers[i]|((long long)1 << j);
                }
            }
            
            if (0 == strcmp("right", command))
            {
                int j;
                for (j = 0; j <= position; j++)
                {
                    counter += (numbers[i] >> j) & (long long)1;
                   // printf("%d\n", counter); 
                }
                                   
                
                for (j = 0; j <=  position; j++)
                {
                    numbers[i] = numbers[i] & (~((long long)1 << j ));
                }
                                              
                for (j = 0; j < counter; j++)
                {
                    numbers[i] = numbers[i] | ((long long)1 << j);
                }
            }   
        } 
        
        
        //printf("%llu\n", numbers[i]);   
        
        fgets(commandLine, COMMAND_SIZE, stdin);   
        sscanf(commandLine, "%s %d", command, &position);
    }
    
    for (i = 0; i < count; i++)
    {
        printf("%llu\n", numbers[i]);
    }

    return 0;
}

