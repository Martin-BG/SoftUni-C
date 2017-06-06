/*Create a task that is checking if 10 numbers that are inputed by the user are :
- odd or even
- multiple of 3
- multiple of 5
- multiple of 19
- the result of division by 10
- the result of division by 17
The data is inputed by the user and separated by ','.
Example:
Input:
2,4,8,15,16,23,42,88,91.7,17
Output:
2 - even, no, no, no, 0.2000, 0.1176
4 - even, no, no, no, 0.4000, 0.2353
8 - even, no, no, no, 0.8000, 0.4706
15 - odd, yes, yes, no, 1.5000, 0.8824
16 - even, no, no, no, 1.6000, 0.9412
23 - odd, no, no, no, 2.3000, 1.3529
and so on ………. */

#include<stdio.h>

int isRealNumber(float);
int isEven(int);
int isMultipleOf3(int);
int isMultipleOf5(int);
int isMultipleOf19(int);
float divisionBy10(float);
float divisionBy17(float);
void processNumber(float);

int main(void)
{
    printf("Enter numbers: ");

    float temp, i;

    for (i = 0; i < 10; i++)
    {
        scanf("%f,", &temp);
        processNumber(temp);
    }

    return 0;
}

int isRealNumber(float num)
{
    return (num - (int)num != 0.0f);
}

int isEven(int num)
{
    return (num % 2 == 0);
}

int isMultipleOf3(int num)
{
    return (num % 3 == 0);
}

int isMultipleOf5(int num)
{
    return (num % 5 == 0);
}

int isMultipleOf19(int num)
{
    return (num % 19 == 0);
}

float divisionBy10(float num)
{
    return (num / 10.0f);
}

float divisionBy17(float num)
{
    return (num / 17.0f);
}

void processNumber(float num)
{
    static int first = 0;

    if (first == 0)
    {
        printf("\n%9s - %4s, %3s, %3s, %3s, %6s, %6s\n",
               "Number", "Type", "^3", "^5", "^19", "n / 10", "n / 17");
        first = 1;
    }

    if (isRealNumber(num))
    {
        printf("%9f - real, yes, yes, yes, %.4f, %.4f\n",
               num,
               divisionBy10(num),
               divisionBy17(num));
    }
    else
    {
        int number = num;
        printf("%9d - %4s, %3s, %3s, %3s, %.4f, %.4f\n",
               number,
               isEven(number)?"even":"odd",
               isMultipleOf3(number)?"yes":"no",
               isMultipleOf5(number)?"yes":"no",
               isMultipleOf19(number)?"yes":"no",
               divisionBy10(num),
               divisionBy17(num));
    }
}
