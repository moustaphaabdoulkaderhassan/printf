#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
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
		}
		else
		{
			i++;
			if (format[i] == 'b')
			{
				unsigned int num = va_arg(args, unsigned int);
				_print_binary(num);
			}
			else if (format[i] == 'c')
			{
				char c = (char) va_arg(args, int);
				write(STDOUT_FILENO, &c, 1);
				count++;
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				_print_digits(va_arg(args, int), &count);
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(args, char *);
				_print_string(str, &count);
			}
		}
	}

	va_end(args);
	return count;
}
