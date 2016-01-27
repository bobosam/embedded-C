#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BUFFER_SIZE 4096
#define TIME_SIZE 12
#define OFFSET_TO_ENDTIME 4

void kill(char *msg);
void check_input(int matches);
void change_time(char *input, int offset);
int check_buffer(char *buffer, char *matches, size_t readBytes);

int main(void)
{
    int offset, matches;
    char *filePath = "source.sub";
    char *destPath = "fixed.sub";
    
    printf("offset --> ");
    matches = scanf("%d", &offset);
    check_input(matches);
    
    FILE *file = fopen(filePath, "r");
    FILE *dest = fopen(destPath, "w");
    
    if (NULL == dest || NULL == file) 
    {
        kill(NULL);
    }
    
    char buffer[BUFFER_SIZE];
    char *timeEnd;
    char *timeStart;
    
    while ((0 == feof(file)) && (0 == ferror(file)) && (0 == ferror(dest)))
    {
        size_t readBytes = fread(buffer, 1, BUFFER_SIZE, file);
        char *substr;
        substr = strstr(buffer, "-->");
        while (NULL != substr)
        {
            int check = check_buffer(buffer, substr, readBytes);
            
            if (1 == check) 
            {
                timeEnd = substr + OFFSET_TO_ENDTIME;
                timeStart = substr - TIME_SIZE -1;
                char startTime[TIME_SIZE + 1];
                strncpy(startTime, timeStart, TIME_SIZE);
                startTime[TIME_SIZE] = '\0';
                char endTime[TIME_SIZE +1];
                strncpy(endTime, timeEnd, TIME_SIZE);
                endTime[TIME_SIZE] = '\0';

                change_time(startTime, offset);
                strncpy(timeStart, startTime, TIME_SIZE);
                change_time(endTime, offset);
                strncpy(timeEnd, endTime, TIME_SIZE);
            } 
            
            substr = strstr(timeEnd, "-->");
        }
        
        fwrite(buffer, 1, readBytes, dest);
    }
    
    fclose(file);
    fclose(dest);

    return 0;
}

int check_buffer(char *buffer, char *matches, size_t readBytes)
{
    int check = 1;
    if (((matches - buffer) + OFFSET_TO_ENDTIME + TIME_SIZE) > readBytes)
    {
        check = 0;
    }
    
    if ((matches - TIME_SIZE - 1) < buffer)
    {
        check = 0;
    }
    
    return check;
}

void change_time(char *input, int offset)
{
    int milliseconds, seconds, minutes, hours, rem;
    char time[13];
    strcpy(time, input);
    sscanf( time, "%d:%d:%d,%d\n", &hours, &minutes, &seconds, &milliseconds );
    milliseconds = milliseconds + offset;
    if (999 < milliseconds)
    {
        rem = milliseconds / 1000;
        milliseconds = milliseconds %1000;
        seconds = seconds + rem;
        if (59 < seconds)
        {
            rem = seconds /60;
            seconds = seconds %60;
            minutes = minutes + rem;
            if (59 < minutes)
            {
                rem = minutes / 60;
                minutes = minutes %60;
                hours = hours + rem;
            }
        }
    }
    
    char newTime[13];
    sprintf(newTime, "%02d:%02d:%02d,%03d", hours, minutes, seconds, milliseconds);
    strcpy(input, newTime);
}

void check_input(int matches)
{
    if (1 != matches)
    {
        printf("Wrong number!");
        exit(1);
    }
}

void kill(char *msg)
{
    if (0 != errno) 
    {
        perror(msg);
    }
    else
    {
        fprintf(stderr, "%s\n", msg);
    }
}
