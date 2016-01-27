#include <stdio.h>

int main(void) 
{
    int firstStartNumber = 2;
    int secondStartNumber = -3;
    int i, n;
    scanf("%d", &n);
    
    int counter = 0;
    
    for(i = 0; i <= n / 2; i++)
    {
        if(counter < n)
        {
            printf("%d ", firstStartNumber + (2 * i));
        }
        
        counter ++;
        if(counter < n)
        {
            printf("%d ", secondStartNumber - (2 * i));
        }
        counter ++;
    }

    return 0;
}

