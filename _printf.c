#include <main.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: Format string with conversion specifiers
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
const char *ptr;
va_start(args, format);

for (ptr = format; *ptr != '\0'; ptr++)
{
if (*ptr == '%')
{
ptr++; /* Move to the next character after '%' */

switch (*ptr)
{
                case 'c':
                    count += write(1, &(va_arg(args, int)), 1);
                    break;
                case 's':
                    count += write(1, va_arg(args, char *), strlen(va_arg(args, char *)));
                    break;
                case '%':
                    count += write(1, "%", 1);
                    break;
                default:
                    count += write(1, "%", 1);
                    count += write(1, &(*ptr), 1);
                    break;
            }
        }
        else
        {
            count += write(1, &(*ptr), 1);
        }
    }

    va_end(args);

    return count;
}

int main(void)
{
    _printf("Character: %c\n", 'H');
    _printf("String: %s\n", "Hello, World!");
    _printf("Percent: %%\n");

    return (0);
}
