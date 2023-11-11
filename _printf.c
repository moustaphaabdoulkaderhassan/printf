#include <unistd.h>
#include <stdarg.h>

int print_char(char c) {
    return write(1, &c, 1);
}

int print_str(const char *str) {
    int n = 0;
    while (*str) {
        n += write(1, str++, 1);
    }
    return n;
}

int print_binary(unsigned int num) {
    char buffer[32];  // Assuming 32-bit integers
    int bit, n = 0;

    for (bit = 31; bit >= 0; bit--) {
        buffer[31 - bit] = ((num >> bit) & 1) + '0';
    }

    return write(1, buffer, 32);  // Adjust if needed
}

int _printf(const char *format, ...) {
    if (format == NULL) {
        return -1;
    }

    int n = 0;
    va_list ap;
    va_start(ap, format);

    for (const char *p = format; *p; p++) {
        if (*p != '%') {
            n += print_char(*p);
        } else {
            p++;
            if (*p == 's') {
                n += print_str(va_arg(ap, const char *));
            } else if (*p == 'c') {
                n += print_char(va_arg(ap, int));
            } else if (*p == 'b') {
                n += print_binary(va_arg(ap, unsigned int));
            }
            // Add more cases for other format specifiers if needed
        }
    }

    va_end(ap);

    return n;
}

int main(void) {
    _printf("Testing %s, %c, and %b\n", "Hello", 'A', 98);
    return 0;
}
