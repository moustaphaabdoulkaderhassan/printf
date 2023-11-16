#include "main.h"

/**
 * control_print- Prints an argument based on its type
 * @args: list of arguments
 * @i: index used to traverse.
 * @p: Array
 * @format: Formatted string in which to print the arguments.
 *
 * Return: (0) or (-1).
 */
int control_print(const char *format, int *i, va_list args, convert p[])
{
	int width = 0;

	width = fetch_width(format, i, args);

	if (width < 0)
	{
		return (-1);
	}

	_putchar('<');
	_putchar(p[*i].ph[0]);
	_putchar(p[*i].ph[1]);
	_putchar('>');
	return (0);
}
