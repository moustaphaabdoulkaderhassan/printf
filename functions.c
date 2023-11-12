#include <stdio.h>
#include <stdarg.h>
#include "printf.h"

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0; // to keep track of the number of characters printed

    while (*format != '\0') {
        if (*format == '%') {
            format++; // move to the next character after '%'

            switch (*format) {
                case 'c':
                    // %c: Character
                    putchar(va_arg(args, int));
                    count++;
                    break;
                    
                case 's':
                    // %s: String
                    {
                        const char *str = va_arg(args, const char *);
                        while (*str != '\0') {
                            putchar(*str);
                            str++;
                            count++;
                        }
                    }
                    break;

                case 'd':
                case 'i':
                    // %d, %i: Integer
                    {
                        int num = va_arg(args, int);
                        printf("%d", num);
                        count++;
                    }
                    break;

                case '%':
                    // %%: Percent sign
                    putchar('%');
                    count++;
                    break;

                default:
                    // Unknown specifier, just print it as is
                    putchar('%');
                    putchar(*format);
                    count += 2;
            }
        } else {
            // Regular character, just print it
            putchar(*format);
            count++;
        }

        format++; // move to the next character in the format string
    }

    va_end(args);
    return count;
}