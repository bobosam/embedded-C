#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 4096

void kill (const char *msg);

int main(void) {

    

    return 0;
}

void kill (const char *msg)
{
    if (errno) 
    {
      perror(msg);      
    }
    else{
        fprintf(stderr, "%s\n", msg);
    }
}