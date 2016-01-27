#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

char *sub_str(char * src, int position, int length);

int main(void)
{
    char *resultBa = NULL;
    resultBa = sub_str("Breaking Bad", 0, 2);
    printf("substring --> %s\n", resultBa);
    
    char *resultIac = sub_str("Maniac", 3, 3);
    printf("substring --> %s\n", resultIac);
    
    char *iacResult = sub_str("Maniac", 3, 5);
    printf("substring --> %s\n", iacResult);
    
    char *resultEmpty = sub_str("Master Yoda", 13, 5);
    printf("substring --> %s\n", resultEmpty);
    
    free(resultBa);
    free(resultIac);
    free(iacResult);
    free(resultEmpty);
         
    return 0;
}

char *sub_str(char * src, int position, int length)
{
    char *resultString = malloc(MAX_SIZE);
    
    if (NULL == resultString)
    {
        printf("Out of memory");
        exit(1);
    }
        
    int stringLength = strlen(src);
    
    if (0 > position || (stringLength - 1) < position)
    {
        strcpy(resultString, "(empty string)");
        return resultString;
    } 
    
    if ((position + length) > stringLength)
    {
        length = stringLength - position;
    }

    int i;
    for (i = 0; i < length; i++)
    {
        resultString[i] = src[position + i];
    }
    
    resultString[i] = '\0';

    return resultString;
}

