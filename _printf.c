#include "main.h"

void prints_buffer(char buffer[], int *ind_buffer);


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
	int i, printed = 0, chrs_printed = 0;
	int flags, width, precision, size, ind_buff = 0;
	va_list list;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[ind_buff++] = format[i];
			if (ind_buff == BUFFER_SIZE)
				prints_buffer(buffer, &ind_buff);
			/*write(1, &format[i], 1); */
			chrs_printed++;
		}
		else
		{
			prints_buffer(buffer, &ind_buff);
			flags = fetch_flags(format, &i);
			width = fetch_width(format, &i, list);
			precision = fetch_precision(format, &i, list);
			size = fetch_size(format, &i);
			++i;
			printed = control_print( format, &i, list, buffer, flags, width, precision, size);
			if (printed == -1)
				return (-1);
			chrs_printed += printed;
		}
	}

	prints_buffer(buffer, &ind_buff);

	va_end(list);

	return (chrs_printed);
}

/**
 *prints_buffer - Prints the contents of the buffer, if it exist
 *@buffer: Array of chars
 *@ind_buff: The Index at which to add next Characters, represents the length.
 */
void prints_buffer(char buffer[], int *ind_buff)
{
	if (*ind_buff > 0)
		write(1, &buffer[0], *ind_buff);

	*ind_buff = 0;
}
