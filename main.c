#include <stdio.h>
#include "printf.h"

int main() {
    // Test cases for _printf function

    // Test case 1: Print a character
    _printf("Character: %c\n", 'A');

    // Test case 2: Print a string
    _printf("String: %s\n", "Hello, World!");

    // Test case 3: Print a percent sign
    _printf("Percent sign: %%\n");

    // Test case 4: Combination of characters and strings
    _printf("Combination: %c %s %%%c\n", 'X', "Testing", 'Y');

    return 0;

