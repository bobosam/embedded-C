#include <stdio.h>

void checkInput(int matches);

int main(void)
{
    int i, j, k, l, numbers[5], matches, number, sum = 0, isZeroSum = 1;
    
    for (i = 0; i < 5; i++)
    {
        printf("Enter a number %d --> ", i+1);
        matches = scanf("%d", &number);
        checkInput(matches);
        numbers[i] = number;
    }
    
    for (i = 0; i < 5; i++)
    {
        for (j = i + 1; j < 5; j++)
        {
            sum = numbers[i] + numbers[j];
            if (0 == sum)
            {
                printf("%d + %d = 0\n", numbers[i], numbers[j]);
                isZeroSum = 0;
            }

        }

    }
    
    for (i = 0; i < 5; i++)
    {
        for (j = i + 1; j < 5; j++)
        {
            for (k = j +1; k < 5; k++) 
            {
                sum = numbers[i] + numbers[j] + numbers[k];
                if (0 == sum)
                {
                    printf("%d + %d + %d = 0\n", numbers[i], numbers[j], numbers[k]);
                    isZeroSum = 0;
                }
            }          
        }
    }
    
    for (i = 0; i < 5; i++)
    {
        for (j = i + 1; j < 5; j++)
        {
            for (k = j +1; k < 5; k++) 
            {
                for (l = k + 1; l < 5; l++)
                {
                    sum = numbers[i] + numbers[j] + numbers[k] + numbers[l];
                    if (0 == sum)
                    {
                        printf("%d + %d + %d + %d = 0\n",
                                numbers[i], numbers[j], numbers[k], numbers[l]);
                        isZeroSum = 0;
                    }
                }               
            }          
        }
    }

    sum = numbers[0] + numbers[1] + numbers[2] + numbers[3] + numbers[4];
    if (0 == sum)
    {
        printf("%d + %d + %d + %d + %d = 0\n",
                numbers[0], numbers[1], numbers[2], numbers[3], numbers[4] );
        isZeroSum = 0;
    }
    
    if (isZeroSum)
    {
        printf("no zero subset");
    }


    return 0;
}

void checkInput(int matches)
{
    if (1 != matches)
    {
        printf("Wrong number!");
        exit(1);
    }

}

