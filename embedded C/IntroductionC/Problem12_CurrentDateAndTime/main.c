#include <time.h>
#include <stdio.h>

int main(void)
{            
    time_t timer;
    char buffer[26];
    struct tm* tm_info;

    time(&timer);
    tm_info = localtime(&timer);

    strftime(buffer, 26, "%d %B %Y %H:%M:%S", tm_info);
    puts(buffer);

    return 0;
}