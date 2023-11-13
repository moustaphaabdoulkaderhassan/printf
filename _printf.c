#include "main.h"

/**
 * _printf - Custom printf function.
 * @format: Format string with %s, %c, %b, %i, %d specifiers.
 *
 * Description:
 * This function mimics the behavior of the standard printf function with a
 * subset of format specifiers. It iterates through the format string, printing
 * characters directly or interpreting format specifiers to print corresponding
 * values.
 *
 * Return: The total number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list ap;
	const char *p;
	int n = 0;

	if (format == NULL)
	{
		return -1;
	}

	va_start(ap, format);

	for (p = format; *p != '\0'; p++)
	{
		if (*p != '%')
		{
			n += print_chr(*p);
		}
		else
		{
			p++;
			if (*p == 's')
			{
				n += print_str(va_arg(ap, const char *));
			}
			else if (*p == 'c')
			{
				n += print_chr(va_arg(ap, int));
			}
			else if (*p == 'b')
			{
				n += print_binry(va_arg(ap, unsigned int));
			}
			else if (*p == 'i' || *p == 'd')
			{
				n += print_int(va_arg(ap, int));
			}
		}
	}

	va_end(ap);

	return n;
}
