/*Task 1:
Make a program that is creating and printing an array
of long integers inputed by user. First the user inputs
the count of the numbers that he wants to input, then
the user inputs numbers one by one.
For example if the user wants to input 4 numbers,
first of all he/she inputs the number '4', then
the first number, enter, second number, enter,
third number, enter, forth number, enter.
At the end the program prints all the numbers.*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Enter number of elements to read: ");
    int elements;
    scanf("%d", &elements);

    long int * numbers = malloc(sizeof(long int) * elements);

    int element;
    for (element = 0; element < elements; element++)
    {
        printf("Enter number (%d): ", element + 1);
        scanf("%ld", &numbers[element]);
    }

    printf("\nYour numbers are:\n");
    for (element = 0; element < elements; element++)
    {
        printf("%d: %ld\n", element + 1, numbers[element]);
    }

    free(numbers);

    return 0;
}
