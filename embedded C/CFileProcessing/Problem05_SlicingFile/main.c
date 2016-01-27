#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 4096
#define MAX_SIZE_DEST_NAME 20

char **slice(const char *sourceFile, size_t count);
void assemble(const char **parts, const char *destinationDirectory, size_t count);
void check_input(int matches);
void kill(const char *msg);

int main(int argc, char *argv[]) 
{
    char *ptr;
    long count = strtol(argv[3], &ptr, 10);
    if ((0 != errno) || (ptr == argv[3]))
    {
        kill("Conversion error!");
    }

//    int count, matches;
//    
//    printf("Enter count of parts --> ");
//    matches = scanf("%d", &count);
//    check_input(matches);
       
    char filePath[MAX_SIZE_DEST_NAME];
    strcpy(filePath, argv[1]);
    char assembleDestPath[MAX_SIZE_DEST_NAME];
    strcpy(assembleDestPath, argv[2]);
    
//    const char *filePath = "vihren.jpg";
//    const char *assembleDestPath = "assemble_vihren.jpg";
    
    char **namesPtr = slice((const char*)filePath, count);
    
    assemble((const char**)namesPtr, (const char*)assembleDestPath, count);
    
    int i;
    for (i = 0; i < count; i++)
    {
        free(namesPtr[i]);
    }   
    
    free(namesPtr);
        
    return 0;
}

void assemble(const char **parts, const char *destinationDirectory, size_t count)
{
    FILE *dest = fopen(destinationDirectory, "w");
    if(NULL == dest)
    {
        kill(NULL);
    }
    
    char buffer[BUFFER_SIZE];
    int i;
    for (i = 0; i < count; i++)
    {
        FILE *currentPart = fopen(parts[i], "r");
        if (NULL == currentPart)
        {
            kill(NULL);
        }

        while (!(feof(currentPart) ||
                ferror(dest) || 
                ferror(currentPart))) 
        {
            size_t readBytes = fread(buffer, 1, BUFFER_SIZE, currentPart);
            fwrite(buffer, 1, readBytes, dest);
        }
        
        fclose(currentPart);
    }

    fclose(dest);
}

char **slice(const char *sourceFile, size_t count)
{
    int len = strlen(sourceFile);
    char destination[len + 1];
    strcpy(destination, sourceFile);
    char *nameDest = strtok(destination, ".");
    
    FILE *file = fopen(sourceFile, "r");
    if (NULL == file)
    {
        kill(sourceFile);
    }
    
    fseek(file, 0, SEEK_END);
    unsigned long long position = ftell(file);
    fseek(file, 0, SEEK_SET);
    unsigned long long partSize = position / count + 1;
    char buffer[BUFFER_SIZE];
    
    char **namesPtr = malloc(count * sizeof(char*));
    
    int i;
    for (i = 0; i < count; i++)
    {
        char *name = malloc(MAX_SIZE_DEST_NAME);
        sprintf(name, "slice_%s-%d.jpg", nameDest, i);
        namesPtr[i] = name;
                       
        FILE *dest = fopen(name, "w");
        if (NULL == dest)
        {
            kill("Could not create a part!");
        }

        size_t writenBytes = 0;
        while ((writenBytes <= partSize) && (0 == feof(file))) 
        {
            size_t readBytes = fread(buffer, 1, BUFFER_SIZE, file);
            fwrite(buffer, 1, readBytes, dest);
            writenBytes += readBytes;
        }

        fclose(dest);
    }

    fclose(file);
    
    return namesPtr;
}

void kill(const char *msg)
{
    if(0 != errno)
    {
        perror(msg);
    }
    else
    {
        fprintf(stderr, "%s\n", msg);
    }
}

void check_input(int matches)
{
    if (1 != matches)
    {
        printf("Wrong number!");
        exit(1);
    }
}