#include "main.h"

/**
 * formatted_print - Custom printf function handling conversion specifiers
 * @format: Format string with conversion specifiers
 * @...: Variable args corresponding to specifiers
 *
 * Returns: Number of characters printed (excluding null byte)
 */
int formatted_print(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int count = 0;

	for (int i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			write(STDOUT_FILENO, &format[i], 1);
			count++;
			continue;
		}

		i++;

		if (format[i] == 'd')
		{
			_print_digits(va_arg(args, int), &count);
		}
		else if (format[i] == 'u')
		{
			_print_unsigned(va_arg(args, unsigned int), &count);
		}
		else if (format[i] == 'o')
		{
			_print_octal(va_arg(args, unsigned int), &count);
		}
		else if (format[i] == 'x')
		{
			_print_hex(va_arg(args, unsigned int), "0123456789abcdef", &count);
		}
		else if (format[i] == 'X')
		{
			_print_hex(va_arg(args, unsigned int), "0123456789ABCDEF", &count);
		}
		else if (format[i] == 's')
		{
			_print_string(va_arg(args, char *), &count);
		}
		else if (format[i] == 'c')
		{
			_print_char(va_arg(args, int), &count);
		}
		else
			write(STDOUT_FILENO, "Unsupported specifier", 21);
		count += 21;
	}
	va_end(args);
	return (count);
}
