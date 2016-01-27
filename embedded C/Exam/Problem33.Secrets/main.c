#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 64

void kill(const char *msg);
void file_kill(FILE *stream, char *fileName, char *msg);

int main(int argc, char *argv[])
{
    
    int len = strlen(argv[1]);
    
    char fileInput[len + 1];
    strcpy(fileInput, argv[1]);
    
    int countFiles = argc - 1;
    
    char *fileName = strtok(fileInput, ".");
    char *extension = strtok(NULL, ".");
    int extLen = strlen(extension);
    char outName[] = "merged.";
    strcat(outName, extension);
    FILE *result = fopen(outName, "w");
    if (!result)
    {
        kill(NULL);
    }

    char buffer[BUFFER_SIZE];
    
    char apple[4] = {0x33, 0x34, 0x35, 0x36};
    char leaf[4] = {0x21, 0x22, 0x23, 0x24};
    
    int i;
    for (i = 1; i <= countFiles; i++)
    {
        FILE *currentPart = fopen(argv[i], "r");
        if (!currentPart)
        {
            file_kill(result, outName, argv[i]);
        }
        
        while (1)
        {
            size_t readBytes = fread(buffer, 1, BUFFER_SIZE, currentPart);
            if (0 == readBytes)
            {
                break;
            }
            
            size_t writtenBytes;
            char *curreentSign = buffer + readBytes -4;
            
            if (0 == memcmp(curreentSign, apple, 4))
            {
                writtenBytes = fwrite(buffer, 1 ,readBytes - 4, result);
            }
            else if(0 == memcmp(curreentSign, leaf, 4))
            {
                writtenBytes = fwrite(buffer, 1 ,(readBytes - 4) / 2, result);
            }
            else
            {
                continue;
            }
            
            if (0 == writtenBytes)
            {
                break;
            }

        }
        
        if (ferror(currentPart))
        {
            fclose((currentPart));
            file_kill(result, outName, "Error reading from part\n");
        }
        
        if (ferror(result)) 
        {
            fclose(currentPart);
            file_kill(result, outName, "Error writing to result\n");
        }

        fclose(currentPart);
    }
    
    fclose(result);
    printf("Done!");

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
    
    exit(1);
}

void file_kill(FILE *stream, char *fileName, char *msg)
{
    fclose(stream);
    remove(fileName);
    kill(msg);
}
