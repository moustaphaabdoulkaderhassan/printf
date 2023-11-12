#include "main.h"

/**
 * _printf - is the Printf function
 * @format: format.
 * Return: Printed characterss.
 */
int _printf(const char *format, ...)
{
	if (format == NULL)
	{
		return -1;
	}

	va_list ap;
	va_start(ap, format);

	int n = 0;
	const char *p;

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
