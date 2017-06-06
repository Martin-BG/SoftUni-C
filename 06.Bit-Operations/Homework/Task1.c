/*Make a program that is getting user inputed decimal number and
is translating it to hexadecimal and octal numeral systems.
Example input : 11
Example output:
HEX: 0xB
OCT: 0o13*/

#include <stdio.h>

void printAsHex(unsigned int);
void printAsOct(unsigned int);

int main(void)
{
    unsigned int decimal_num;

    printf("Enter a positive decimal number up to 4294967295: ");
    scanf("%u", &decimal_num);

    printAsHex(decimal_num);
    printAsOct(decimal_num);

    return 0;
}

void printAsHex(unsigned int num)
{
    char hex_nums[16] = "0123456789ABCDEF";
    char hex_number[8] ="00000000";
    unsigned int mask = 15;

    int index = 0;

    while (num > 0 && index < 8)
    {
        hex_number[index++] = hex_nums[num & mask];
        num >>= 4;
    }

    index--;

    printf("HEX: 0x");

    while(index >= 0)
    {
        printf("%c", hex_number[index--]);
    }

    printf("\n");
}

void printAsOct(unsigned int num)
{
    char oct_nums[8] = "01234567";
    char oct_number[11] = "00000000000";
    unsigned int mask = 7;

    int index = 0;

    while (num > 0 && index < 11)
    {
        oct_number[index++] = oct_nums[num & mask];
        num >>= 3;
    }

    index--;

    printf("OCT: 0o");

    while(index >= 0)
    {
        printf("%c", oct_number[index--]);
    }

    printf("\n");
}
