#include <stdio.h>
#include <string.h>

int main(void) 
{
    printf("Enter gender Male or Female: ");
    char gender[7];
    scanf("%6s", gender);
    int isFemale = strcmp(gender, "Female");
    printf("%s", isFemale ? "false" : "true"); 
    
    return 0;
}

