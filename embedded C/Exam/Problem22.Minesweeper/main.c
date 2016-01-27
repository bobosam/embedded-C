#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SetBitAtPosition(unsigned long long * number, int position, int bit);
int GetBitAtPosition(unsigned long long number, int position);

int main(void) 
{
    int n;
    char command[10];
    int row = 0;
    int col = 0;
    int newRow = 0;
    int newCol = 0;
      
    scanf("%d", &n);
    unsigned long long numbers[n];
    
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%llu", &numbers[i]);
    }
    
    scanf("%s", command);
    
    while (0 != strncmp("end", command, 3))
    {
        if (0 == strncmp("right", command, 5))
        {
            newCol--;
            if (-1 == newCol)
            {
                newCol = 31;
            }
        }
        
        if (0 == strncmp("left", command, 4))
        {
            newCol++;
            if (32 == newCol)
            {
                newCol = 0;
            }
        }
        
        if (0 == strncmp("up", command, 2))
        {
            newRow--;
            if (-1 == newRow)
            {
                newRow = n -1;
            }
        }
        
        if (0 == strncmp("down", command, 4))
        {
            newRow++;
            if (n == newRow)
            {
                newRow = 0;
            }
        }
        
        int mine = GetBitAtPosition(numbers[newRow], newCol);
        
        if (1 == mine)
        {
            printf("GAME OVER. Stepped a mine at %d %d\n", newRow, newCol);
            
            break;
        }

        SetBitAtPosition(&numbers[row], col, 0);
        SetBitAtPosition(&numbers[newRow], newCol, 1);
        row = newRow;
        col = newCol;
        
        scanf("%s", command);
    }


    for (i = 0; i < n; i++)
    {
        printf("%llu\n", numbers[i]);
    }


    return 0;
}

void SetBitAtPosition(unsigned long long *number, int position, int bit)
{
    if (bit == 0)
    {
        (*number) &= ( ~((long long)1 << position));
    }
    else
    {
        (*number) |= (long long)1 << position;
    }
}


int GetBitAtPosition( unsigned long long number, int position)
{
    return (number >> position) & 1;
}

