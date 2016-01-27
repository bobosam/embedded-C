#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COUNT 11

int main(void)
{
    char *line = NULL;
    int len = 0;
    char *strings[MAX_COUNT];
    int index = 0;
    char number[MAX_COUNT];
    double floatNumber;
    long double sum = 0;
    double result = 0;
    
    getline(&line, &len, stdin);
    int length = strlen(line);
    if ('\n' == line[length - 1])
    {
        line[length - 1] = '\0';
    }
    
    strings[index] = strtok(line, " ");
    while (NULL != strings[index])
    {
        index++;
        strings[index] = strtok(NULL, " ");
    }
    
    int i;
    for (i = 0; i < index; i++)
    {
        length = strlen(strings[i]);
        int j;
        for (j = 1; j < length - 1; j++)
        {
            number[j-1] = strings[i][j];
        }
        
        number[j - 1] = '\0';
        floatNumber = atof(number);

        if ('A' <= strings[i][0] && ('Z' >= strings[i][0]))
        {
            int digit = strings[i][0] - 'A' + 1;
            result = floatNumber / digit;
            printf("%f\n", result);
        }
        
        if ('a' <= strings[i][0] && ('z' >= strings[i][0]))
        {
            int digit = strings[i][0] - 'a' + 1;
            result = floatNumber * digit;
             printf("%f\n", result);
        }
       
        if ('A' <= strings[i][length - 1] && ('Z' >= strings[i][length - 1]))
        {
            int digit = strings[i][length - 1] - 'A' + 1;
            result = result - digit;
             printf("%f\n", result);
        }
        
        if ('a' <= strings[i][length - 1] && ('z' >= strings[i][length - 1]))
        {
            int digit = strings[i][length - 1] - 'a' + 1;
            result = result + digit;
             printf("%f\n", result);
        }
        
        sum += result;
        
    }
    
    if (5 == ((int)(sum * 1000))%10)
        {
            sum += 0.001;
        }

    printf("%.2Lf", sum);

    return 0;
}

