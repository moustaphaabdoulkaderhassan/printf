#include <stdio.h>

int main() {
    // Handle the + flag
    int positiveNumber = 42;
    printf("Positive number with + flag: %+d\n", positiveNumber);

    // Handle the space flag
    int anotherPositiveNumber = 99;
    printf("Positive number with space flag: % d\n", anotherPositiveNumber);

    // Handle the l length modifier
    long longNumber = 1234567890L;
    printf("Long integer with l modifier: %ld\n", longNumber);

    // Handle the h length modifier
    short shortNumber = 32767;
    printf("Short integer with h modifier: %hd\n", shortNumber);

    // Conversion specifiers
    int decimalInt = 42;
    printf("Decimal integer: %d\n", decimalInt);

    int octalInt = 077; // Octal literal
    printf("Octal integer: %o\n", octalInt);

    int hexadecimalInt = 0x2A; // Hexadecimal literal
    printf("Lowercase Hexadecimal integer: %x\n", hexadecimalInt);

    printf("Uppercase Hexadecimal integer: %X\n", hexadecimalInt);

    // Handle field width
    int num = 123;
    printf("Field width of 5: %5d\n", num);
    
    return 0;
}

