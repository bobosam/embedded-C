#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 10

int main(void) 
{
    char *xml = NULL;
    int len = 0;
    char *xmlArr[MAX_SIZE];
    int index = 0;
    
    printf("enter xml line --> ");
    getline(&xml, &len, stdin);
    int length = strlen(xml);
    if ('\n' == xml[length - 1])
    {
        xml[length - 1] = '\0';
    }
    
    xmlArr[index] = strtok(xml, "<>");
    while (NULL != xmlArr[index])
    {
        index++;
        xmlArr[index] = strtok(NULL, "<>");
    }

    if ((3 != index) || ('/' != xmlArr[2][0]))
    {
        printf("Invalid format!");
        exit(1);
    }

    xmlArr[0][0] = toupper(xmlArr[0][0]);   
    printf("%s: %s", xmlArr[0], xmlArr[1]);   
    free(xml);

    return 0;
}

