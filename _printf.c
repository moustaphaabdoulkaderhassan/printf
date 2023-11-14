#include "main.h"

void print_buff(char buffer[], int *ind_buff);

/**
 *_printf - Custom printf function
 *@format: Format string
 *
 *Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list list;
	int i = 0, chrs_printed = 0;
	char buffer[BUFFER_SIZE];

	va_start(list, format);

	while (format && format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			int flags, width, precision, size;
			flags = fetch_flags(format, &i);
			width = fetch_width(format, &i, list);
			precision = fetch_precision(format, &i, list);
			size = fetch_size(format, &i);

			chrs_printed += control_print(format, &i, list, buffer, flags, width, precision, size);
		}
		else
		{
			buffer[0] = format[i];
			buffer[1] = '\0';
			chrs_printed += handle_write_char(format[i], buffer, 0, 0, 0, 0);
			i++;
		}
	}

	va_end(list);

	return (chrs_printed);
}
