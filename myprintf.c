#include "myprintf.h"
#include <stdio.h>

void handle_flags(char specifier, int value, int plusFlag, int spaceFlag, int hashFlag) {
    // Logic to handle the specified flags
    // Modify the value according to the flags

    if (plusFlag && value >= 0) {
        putchar('+');
    } else if (spaceFlag && value >= 0) {
        putchar(' ');
    }

    // Additional logic for handling other flags, e.g., hashFlag

    // Print the modified value
    printf("%d", value);
}

void myprintf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format == '%' && *(format + 1) != '\0') {
            format++; // Move to the character after '%'

            // Assume only %d and %f for simplicity
            if (*format == 'd') {
                int value = va_arg(args, int);
                handle_flags('d', value, 1, 1, 1); // Example: Handle flags for %d
            } else if (*format == 'f') {
                double value = va_arg(args, double);
                handle_flags('f', (int)value, 1, 0, 1); // Example: Handle flags for %f
            } else {
                putchar(*format);
            }
        } else {
            putchar(*format);
        }

        format++;
    }

    va_end(args);
}

