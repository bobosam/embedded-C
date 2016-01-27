#include <stdio.h>

int main(void)
{
    int asciiCod;
    for (asciiCod = 0; asciiCod < 128; asciiCod++)
    {
        printf("%d --> %c\n", asciiCod, asciiCod);
    }

    return 0;
}

