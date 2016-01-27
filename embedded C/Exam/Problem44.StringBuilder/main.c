#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_BUFFER_LENGTH 60

char *get_line(char **bufferPtr, size_t *bufSize);
void resize(char **result, size_t* size);
void kill();

int main(void) {
    char *line = NULL;
    size_t size = 0;

    char *result = (char *) calloc(INITIAL_BUFFER_LENGTH, 1);
    size_t resultSize = INITIAL_BUFFER_LENGTH;
    size_t len = 0;

    while (1) {
        get_line(&line, &size);

        char *command = strtok(line, "-");
        char *str = strtok(NULL, "-");
        char *pos = strtok(NULL, "-");
        if (NULL != str) {
            len = strlen(str);
        }

        if (0 == strncmp(command, "over", 4)) {
            break;
        }

        if (0 == strncmp(command, "concat", 6)) {
            if ((strlen(result) + len) >= resultSize) {
                resize(&result, &resultSize);
            }

            strcat(result, str);
        }

        if (0 == strncmp(command, "insert", 6)) {

            if ((strlen(result) + len) >= resultSize) {
                resize(&result, &resultSize);
            }

            if (NULL != pos) {
                size_t position = atol(pos);
                char tmp[resultSize];
                strcpy(tmp, result + position);
                result[position] = '\0';
                strcat(result, str);
                strcat(result, tmp);
            }
        }

        if (0 == strncmp(command, "replace", 7)) {

            char *match = strstr(result, str);
            while (NULL != match) {

                if ((strlen(result) + strlen(pos)) >= resultSize) {
                    resize(&result, &resultSize);
                }

                int ptr = match - result;
                char tmp[resultSize];
                strcpy(tmp, match + len);
                result[ptr] = '\0';
                strcat(result, pos);
                strcat(result, tmp);
                match = strstr(result + ptr + 1, str);
            }
        }

        printf("%s\n", result);

    }

    printf("%s\n", result);
    free(line);
    free(result);

    return 0;
}

char *get_line(char **bufferPtr, size_t *bufSize) {
    char *result = *bufferPtr;
    size_t size = *bufSize;
    if (result == NULL) {
        result = (char *) malloc(INITIAL_BUFFER_LENGTH);
        size = INITIAL_BUFFER_LENGTH;
        if (!result)
            return NULL;
    }

    size_t i = 0;
    char ch = getchar();
    while (ch != '\n' && ch != EOF) {
        if (i == size - 1) {
            char *resized = (char *) realloc(result, 2 * size);
            if (!resized) {
                return NULL;
            }

            result = resized;
            size *= 2;
        }

        result[i] = ch;
        i++;

        ch = getchar();
    }

    result[i] = '\0';
    *bufferPtr = result;
    *bufSize = size;

    return result;
}

void resize(char **result, size_t* size) {
    char *buffer = *result;
    size_t newSize = *size;
    newSize *= 2;
    char *resized = (char *) realloc(buffer, newSize);
    if (!resized) {
        kill();
    }

    buffer = resized;
    *result = buffer;
    *size = newSize;
}

void kill() {
    perror(NULL);
    exit(1);
}