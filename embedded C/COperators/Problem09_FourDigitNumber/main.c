#include <stdio.h>

int main(void)
{
    int firstDigit, secondDigit, thirdDigit, fourthDigit;
    int number, matches, sum;
    
    printf("Four digit number --> ");
    matches = scanf("%d", &number);
    if (1 != matches || 9999 < number || 1000 > number)
    {
        printf("Wrong number!");
        return 1;
    }
    
    fourthDigit = number %10;
    thirdDigit = (number / 10) %10;
    secondDigit = (number / 100) %10;
    firstDigit = (number / 1000) %10;
    
    sum = firstDigit + secondDigit + thirdDigit + fourthDigit;
    printf("number --> %d\nsum of digits --> %d\n", number, sum);
    printf("reversed --> %d%d%d%d\n", fourthDigit, thirdDigit, secondDigit, firstDigit);
    printf("last digit in front --> %d%d%d%d\n", fourthDigit, firstDigit, secondDigit, thirdDigit);
    printf("second and third digits exchanged --> %d%d%d%d", firstDigit, thirdDigit, secondDigit, fourthDigit);

    return 0;
}

