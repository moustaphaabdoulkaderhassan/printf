#include "main.h"

/**
 * _printf - A function that selects the correct function to print.
 * @format: Is the identifier to look for.
 *
 * Return: The length of string(lenght).
 */
int _printf(const char * const format, ...)
{
	convert p[] = {
		{"%s", print_str}, {"%c", print_chr},
		{"%%", print_cent},
		{"%i", print_integer}, {"%d", print_decimal}, {"%r", print_rev},
		{"%R", print_rot13str}, {"%b", print_binry},
		{"%u", print_unsgnd},
		{"%o", print_oct}, {"%x", print_hexadec}, {"%X", print_hexa},
		{"%S", print_exc_str}, {"%p", print_ptr}
	};

	va_list args;
	int i = 0, j, length = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	while (format[i] != '\0')
	{
		j = 13;
		while (j >= 0)
		{
			if (p[j].ph[0] == format[i] && p[j].ph[1] == format[i + 1])
			{
				length += p[j].function(args);
				i = i + 2;
				goto Here;
			}
			j--;
		}
		_putchar(format[i]);
		length++;
		i++;
	}
	va_end(args);
	return (length);
}
