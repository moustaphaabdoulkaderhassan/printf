#include "main.h"

/**
 * my_printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int my_printf(const char *format, ...)
{
	unsigned int h = 0, r_value = 0;
	va_list args;
	va_start(args, format);

	for (; format[h] != '\0'; h++)
	{
		if (format[h] != '%')
		{
			putchr(format[h]);
		}
		else if (format[h + 1] == '+')
		{
			putchr(va_arg(args, int));
			h++;
		}
		else if (format[h + 1] == 's')
		{
			/* To be continued . . . */
			r_value += 1;
		}
	}
	va_end(args);

	return (r_value);
}

