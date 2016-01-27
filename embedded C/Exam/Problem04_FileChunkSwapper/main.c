#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BUFFER_SIZE 4096

void kill(const char *msg);

int main(int argc, char *argv[] )
{
    if (3 != argc)
    {
        printf("Usage: <src-file> <dest-file>");
    }

    char *srcPath = argv[1];
    char *destPath = argv[2];
    
    FILE *file = fopen(srcPath, "r");
    if (NULL == file)
    {
        printf("src.txt: No such file or directory");
        kill(NULL);
    }
    
    FILE *dest = fopen(destPath, "w");
    if (NULL == dest)
    {
        kill(NULL);
    }
    
    char buffer[BUFFER_SIZE];
    while ((0 == feof(file) && (0 == ferror(file) && (0 == ferror(dest))))) 
    {   
        size_t bytesRead = fread(buffer, 1, BUFFER_SIZE, file);
        if ('\n' == buffer[bytesRead - 1])
        {
            bytesRead--;
        }

//        size_t firstPartSize = bytesRead / 2;
//        size_t secondPartSize = bytesRead - firstPartSize;
//        size_t diff = secondPartSize - firstPartSize;
//        
//        char temp[firstPartSize];
//        memcpy(temp, buffer, firstPartSize);
//        memmove(buffer, buffer + firstPartSize, secondPartSize);
//        memcpy(buffer + firstPartSize + diff, temp, firstPartSize);
        
        size_t first = bytesRead / 2;
        size_t second = bytesRead - first;
        size_t diff = second - first;
        
        char tmp[first];
        memcpy(tmp, buffer, first);
        memmove(buffer, buffer + first, second);
        memcpy(buffer + first + diff, tmp, first);
        
        fwrite(buffer, 1, bytesRead, dest);
        
        printf("Success!");
        
    }

    fclose(file);
    fclose(dest);

    return 0;
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

