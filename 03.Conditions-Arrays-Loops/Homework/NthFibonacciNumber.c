#include <stdio.h>

const int MAX_INDEX = 93;

unsigned long long calcFibonacciNumber(const int*);
void testFibonacciFunction();
int readFibonacciIndexFromConsole();

int main(void)
{
    testFibonacciFunction();

    int index = readFibonacciIndexFromConsole();

    printf("\nFibonacci (%d) = %llu\n", index, calcFibonacciNumber(&index));

    return 0;
}

int readFibonacciIndexFromConsole()
{
    int index;

    while (1)
    {
        printf("\nEnter Fibonacci number index (1-%d): ", MAX_INDEX);

        scanf("%d", &index);

        if (index < 0)
        {
            printf("Error: Input positive number\n");
        }
        else if (index == 0)
        {
            printf("Error: Input larger number than 0\n");
        }
        else if (index > MAX_INDEX)
        {
            printf("Error: Too big number (program supports numbers up to %d)\n", MAX_INDEX);
        }
        else
        {
            break;
        }
    }

    return index;
}

unsigned long long calcFibonacciNumber(const int *index)
{
    unsigned long long fib, prev, temp;

    prev = 0ULL;
    fib = 1ULL;

    int i;
    for (i = 1; i < *index; i++)
    {
        temp = fib;
        fib += prev;
        prev = temp;
    }

    return fib;
}

void testFibonacciFunction()
{
    // http://www.maths.surrey.ac.uk/hosted-sites/R.Knott/Fibonacci/fibtable.html#100
    printf("Test Fibonacci function:\n\n");

    int i;
    for (i = 1; i <= MAX_INDEX; i++)
    {
        printf("Fibonacci (%d) = %llu\n", i, calcFibonacciNumber(&i));
    }

    printf("\nTest Fibonacci function end\n\n");
}
