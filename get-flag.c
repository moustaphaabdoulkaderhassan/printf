#include <stdio.h>
#include <stdarg.h>

void custom_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            format++;

            // Handle flags
            int flag_plus = 0;
            int flag_space = 0;
            int flag_hash = 0;

            // Check for flags
            while (*format == '+' || *format == ' ' || *format == '#') {
                if (*format == '+') {
                    flag_plus = 1;
                } else if (*format == ' ') {
                    flag_space = 1;
                } else if (*format == '#') {
                    flag_hash = 1;
                }
                format++;
            }

            // Handle other conversion specifiers (not implemented in detail here)
            if (*format == 'd' && flag_plus) {
                // Handle '+' flag for integers
                int value = va_arg(args, int);
                printf("%+d", value);
            } else if (*format == 'd' && flag_space) {
                // Handle ' ' flag for integers
                int value = va_arg(args, int);
                printf("% d", value);
            } else if (*format == 'x' && flag_hash) {
                // Handle '#' flag for hexadecimal
                int value = va_arg(args, int);
                printf("0x%x", value);
            } else {
                // Handle other cases (not implemented in detail here)
                putchar('%');
                putchar(*format);
            }
        } else {
            putchar(*format);
        }

        format++;
    }

    va_end(args);
}

int main(void) {
    custom_printf("Examples: %+d, % d, %#x\n", 42, 42, 42);
    return 0;
}

