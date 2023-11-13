#include "main.h"
#include <stdarg.h>
#include <unistd.h>  // Include the necessary header for write function

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte), or -1 on error.
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars;

    if (!format)
        return -1;

    va_start(args, format);
    printed_chars = vfprintf(stdout, format, args);
    va_end(args);

    return printed_chars;
}
