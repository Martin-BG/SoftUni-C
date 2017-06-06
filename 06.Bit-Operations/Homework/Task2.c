/*Task 2:
Implement four functions that are easily doing
multiplication numbers by 2,4,8,16. Names must be :
mult2(int number), mult4(int number),
mult8(int number), mult16(int number).
The multiplication operation should be done
without using the multiply operator.*/

#include <stdio.h>

unsigned int mult2(unsigned int);
unsigned int mult4(unsigned int);
unsigned int mult8(unsigned int);
unsigned int mult16(unsigned int);

int main()
{
    unsigned int decimal_num;

    printf("Enter a positive decimal number: ");
    scanf("%u", &decimal_num);

    printf("%10u (*2)\n", mult2(decimal_num));
    printf("%10u (*4)\n", mult4(decimal_num));
    printf("%10u (*8)\n", mult8(decimal_num));
    printf("%10u (*16)\n", mult16(decimal_num));

    return 0;
}

unsigned int mult2(unsigned int number)
{
    return number<<1;
}

unsigned int mult4(unsigned int number)
{
    return number<<2;
}

unsigned int mult8(unsigned int number)
{
    return number<<3;
}

unsigned int mult16(unsigned int number)
{
    return number<<4;
}
