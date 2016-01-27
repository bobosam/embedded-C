#include <stdio.h>

void check_input(int matches);
void print_array(int array[], int size);

int main(void)
{
    int count, number, matches, maxCount = 0, tmpCount = 0;
    
    printf("count of the numbers --> ");
    matches = scanf("%d", &count);
    check_input(matches);
    
    int array[count];
    int tmpArray[count];
    int maxSequence[count];
    
    int i;
    for (i = 0; i < count; i++)
    {
        printf("number %d --> ", i + 1);
        matches = scanf("%d", &number);
        check_input(matches);
        array[i] = number;
    }
    
    tmpArray[0] = array[0];
    tmpCount++; 
          
    for (i = 1; i < count; i++)
    {    
        if ((array[i] > array[i-1]) && i < (count - 1))
        {
            tmpArray[tmpCount] = array[i];
            tmpCount++;
        }
        else 
        {
            if (array[i] > array[i-1] && i == count - 1)
            {
                tmpArray[tmpCount] = array[i];
                tmpCount++;
            }
            
            if (tmpCount > maxCount)
            {
                maxCount = tmpCount;
                int i;
                for (i = 0; i < maxCount; i++)
                {
                    maxSequence[i] = tmpArray[i];
                }
            }
            
            print_array(tmpArray, tmpCount); 

            tmpArray[0] = array[i];
            tmpCount = 1;
        }
    }
     
    if (array[count-1] <= array[count - 2])
    {
        print_array(tmpArray, tmpCount);
    }   

    printf("Longest : ");
    print_array(maxSequence, maxCount);

    return 0;
}

void print_array(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    
    printf("\n");
}

void check_input(int matches)
{
    if (1 != matches)
    {
        printf("Invalid input!");
        exit(1);
    }
}

