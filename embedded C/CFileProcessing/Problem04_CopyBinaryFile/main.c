#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUFFER_SIZE 4096

int main(void)
{
    copy("sinanica.jpg", "copySinanica.jpg");

    return 0;
}

void copy(const char *srcPath, const char *destPath)
{
    FILE *file = fopen(srcPath, "r");
    if (NULL == file)
    {
        kill(NULL);
        
    }
    
    FILE *dest = fopen(destPath, "w");
    if (NULL == dest)
    {
        kill(NULL);
    }

    char buffer[BUFFER_SIZE];
    while ((0 == feof(file)) && (0 == ferror(file)) && (0 == ferror(dest)))
    {
        size_t bytesRead = fread(buffer, 1, BUFFER_SIZE, file);
        fwrite(buffer, 1, bytesRead, dest);
    }
    
    fclose(file);
    fclose(dest);
}

void kill(const char *msg)
{
    if (errno)
    {
        perror(msg);
    }
    else
    {
        fprintf(stderr, "%s\n", msg);
    }

}