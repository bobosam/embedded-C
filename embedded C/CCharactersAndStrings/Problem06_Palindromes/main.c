#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define cMaxWordSize     100
#define cMaxNumberWords  100

void string_reverse(char *input, char *result, int size);
void print(int row, char *palindromes[]);
void sort(int row, char *palindromes[]);


int main(void) 
{
    char *text = NULL;
    size_t len = 0;
    int count = 0;
    char result[100];
    int index = 0;
    int check = 0;
    
    char* wordsArr[cMaxNumberWords];
    char* palindromes[cMaxNumberWords];
    
       
    printf("text --> ");
    getline(&text, &len, stdin);
    
    wordsArr[count] = strtok(text, ", .?!");
    while ((NULL != wordsArr[count]) && (count < cMaxNumberWords))
    {
        count++;
        wordsArr[count] = strtok(NULL, ", .?!");
    }
       
    int i;
    for (i = 0; i < count; i++) 
    {
        int size = strlen(wordsArr[i]);
        if ('\n' == wordsArr[i][size - 1])
        {
            wordsArr[i][size - 1] = '\0';
            size--;
        }
        
        string_reverse(wordsArr[i], result, size);
                       
        if (0 == strcmp(wordsArr[i], result))
        {
            int j;
            for (j = 0; j < index; j++)
            {
                if (0 == strcmp(wordsArr[i], palindromes[j]))
                {
                    check = 1;
                }
            }

            if (0 == check)
            {
                palindromes[index] = malloc(cMaxWordSize);
                if(palindromes[index] == NULL)
                {
                    exit -1;
                }
                
                strcpy(palindromes[index],wordsArr[i]);
                
                index++;
            }
        }
    }
    
    sort(index, palindromes);
    print(index, palindromes);

    free(text);
    
    return 0;
}

void string_reverse(char *input, char *result, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        result[i] = input[size - i - 1];
    }
    
    *(result + i) = '\0';
}

void print(int row, char *palindromes[])
{
    int k;
    for (k = 0; k < row; k++)
    {
        printf("%s", palindromes[k]);
        if (k < row - 1)
        {
            printf(", ");
        }
        
        free(palindromes[k]);
    }
}

void sort(int row, char *palindromes[])
{
    char temp[100];
    int i;
    for(i = 0;i < row - 1; ++i)
    {
        int j;
        for(j = i + 1;j < row; ++j)
        {
            if(strcasecmp(palindromes[i], palindromes[j])>0)
            {
              strcpy(temp,palindromes[i]);
              strcpy(palindromes[i],palindromes[j]);
              strcpy(palindromes[j],temp);
            }
        }
    }
}