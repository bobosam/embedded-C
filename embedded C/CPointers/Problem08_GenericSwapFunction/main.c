#include <stdio.h>
#include <string.h>

void swap(void *first, void *second, int size);

int main(void)
{
    char letter = 'B', symbol = '+';
    int a = 10, b = 6;
    double d = 3.14, f = 1.23567;
        
    swap(&letter, &symbol, sizeof(char));
    swap(&a, &b, sizeof(int));
    swap(&d, &f, sizeof(double));

    printf("char letters --> ");
    printf("%c %c\n", letter, symbol);

    printf("decimal numbers --> ");
    printf("%d %d\n", a, b);

    printf("float point numbers --> ");
    printf("%.2f %.2f", d, f);

    return 0;
}

void swap(void *first, void *second, int size)
{
    void *tmp;
    tmp = malloc(size);
    
    if (NULL == tmp)
    {
        printf("Out of memory!");
        exit(1);
    }
    
    memcpy(tmp, first, size);
    memcpy(first, second, size);
    memcpy(second, tmp, size);
    
    free(tmp);
}

