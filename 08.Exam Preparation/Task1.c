/*Task 1
Make a program that is printing all negative numbers that are
found in an user inputed array of 200 numbers. The input array
consist of 200 numbers. The numbers are between -200 and +200
and can be numbers with floating point. The input format is
"0.4f", all the numbers are separated by new line character.
The output numbers are separated by ' ' (space character).*/

#include <stdio.h>

#define ELEMENTS 200
float array[ELEMENTS];

int main(void)
{
    int index;
    for (index = 0; index < ELEMENTS; index++)
    {
        scanf("%f", &array[index]);
    }

    for (index = 0; index < ELEMENTS; index++)
    {
        if (array[index] < 0.0f)
        {
            printf("%.4f ", array[index]);
        }
    }

    return 0;
}
