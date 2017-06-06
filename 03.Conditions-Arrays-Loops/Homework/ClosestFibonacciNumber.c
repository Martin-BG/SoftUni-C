#include <stdio.h>

const int MAX_INDEX = 93;

long findClosestFibonacciNumber(const int *, int *);
void testClosestFibonacciNumberFunction();

int main(void)
{
    testClosestFibonacciNumberFunction();

    int input_num, index;
    long closest_num;

    printf("\nEnter control number: ");

    scanf("%d", &input_num);

    closest_num = findClosestFibonacciNumber(&input_num, &index);

    printf("The closest Fibonacci number to %d is %ld (%d)\n", input_num, closest_num, index);

    return 0;
}

long findClosestFibonacciNumber(const int *number, int *index)
{
    long fib, prev, temp;

    if (*number <= 1)
    {
        *index = 1;
        fib = 1L;
    }
    else
    {
        prev = 1L;
        fib = 1L;

        int i;
        for (i = 2; i < MAX_INDEX; i++)
        {
            temp = fib;
            fib += prev;
            prev = temp;

            if (prev <= *number && fib >= *number)
            {
                if (*number - prev <= fib - *number)
                {
                    fib = prev;
                    *index = i;
                }
                else
                {
                    *index = i + 1;
                }

                break;
            }
        }
    }

    return fib;
}

void testClosestFibonacciNumberFunction()
{
    // http://www.maths.surrey.ac.uk/hosted-sites/R.Knott/Fibonacci/fibtable.html#100
    printf("Test closest Fibonacci number function:\n\n");

    int i, index;
    long closest_num;

    for (i = -5; i < 100; i++)
    {
        closest_num = findClosestFibonacciNumber(&i, &index);
        printf("The closest Fibonacci number to %d is %ld (%d)\n", i, closest_num, index);
    }

    printf("\nTest closest Fibonacci number function end\n\n\n");
}
