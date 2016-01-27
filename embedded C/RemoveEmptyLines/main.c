#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *text = fopen("book.txt", "r");
    FILE *dest = fopen("newbook.txt", "w");
    
    if ((NULL == text) || (NULL == dest)) {
        printf("File not open!");
    }
    
    char *line = NULL;
    size_t size = 0;
    
    while (!feof(text)) {
        ssize_t length = getline(&line, &size, text);
        if (0 != strcmp(line, "\n")) {
            fwrite(line, 1, length, dest);
        }
    }
    
    fclose(text);
    fclose(dest);
    
    return 0;
}

