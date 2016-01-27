#include <stdio.h>
#include <string.h>

void strn_cat(char *buffer, char *string, int size);

int main(void)
{
    char buffer[10] = "Soft";
    strn_cat(buffer, "Uni", 7);
    printf("ctring concat --> %s", buffer);

//    char buffer[5] = "Soft";
//    strn_cat(buffer, "ware University", 15); //buffer overflow
//    printf("ctring concat --> %s", buffer);

//    char buffer[10] = "C";
//    strn_cat(buffer, " is cool", 9);
//    printf("ctring concat --> %s", buffer);

//    char * buffer = "C";                //read only
//    strn_cat(buffer, "is cool", 9);
//    printf("ctring concat --> %s", buffer);

    return 0;
}

void strn_cat(char *buffer, char *string, int size)
{
    int bufferLength = strlen(buffer);
    
    int i, index = 0;
    for (i = bufferLength; i < size; i++) 
    {
        buffer[i] = string[index];
        index++;
    }
}

