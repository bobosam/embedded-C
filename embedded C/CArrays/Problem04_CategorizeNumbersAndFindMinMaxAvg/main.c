#include <stdio.h>
#include <float.h>

void check_input(int matches);
void print_array(double array[], int size);
double find_min_number(double array[], int size);
double find_max_number(double array[], int size);
double sum(double array[], int size);
double avg(double array[], int size);

int main(void)
{
    int size, intNumber, matches, roundCount = 0, floatCount = 0;
    double doubleNumber;
    
    printf("count of numbers --> ");
    matches = scanf("%d", &size);
    check_input(matches);
    
    double roundArray[size];
    double floatArray[size];
    
    int i;
    for (i = 0; i < size; i++)
    {
        printf("number %d -- > ", i + 1);
        matches = scanf("%lf", &doubleNumber);
        check_input(matches);
        if (0 == (int)doubleNumber - doubleNumber)
        {
            roundArray[roundCount] = doubleNumber;
            roundCount++;
        }
        else
        {
            floatArray[floatCount] = doubleNumber;
            floatCount++;
        }
    }
    
    double roundMin = find_min_number(roundArray, roundCount);
    double roundMax = find_max_number(roundArray, roundCount);
    double roundSum = sum(roundArray, roundCount);
    double roundAvg = avg(roundArray, roundCount);
    
    double floatMin = find_min_number(floatArray, floatCount);
    double floatMax = find_max_number(floatArray, floatCount);
    double floatSum = sum(floatArray, floatCount);
    double floatAvg = avg(floatArray, floatCount);

    print_array(floatArray, floatCount);
    printf("-> min: %g, max: %g, sum: %g, avg: %.2f\n",
            floatMin, floatMax, floatSum, floatAvg);
    print_array(roundArray, roundCount);
    printf("-> min: %g, max: %g, sum: %g, avg: %.2f\n",
            roundMin, roundMax, roundSum, roundAvg);
    
    return 0;
}

double avg(double array[], int size)
{
    double sumNumbers = sum(array, size);
    double avg = sumNumbers / size;
    
    return avg;
}

double sum(double array[], int size)
{
    double sum = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        sum += array[i];
    }

    return sum;
}

double find_min_number(double array[], int size)
{
    double min = DBL_MAX;
    
    int i;
    for (i = 0; i < size; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }

    return min;
}

double find_max_number(double array[], int size)
{
    double max = DBL_MIN;
    
    int i;
    for (i = 0; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    return max;
}

void print_array(double array[], int size)
{
    printf("[");
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%g", array[i]);
        if (i < size - 1)
        {
            printf(", ");
        }
    }
    
    printf("] ");
}

void check_input(int matches)
{
    if (1 != matches)
    {
        printf("Wrong number!");
        exit(1);
    }
}


