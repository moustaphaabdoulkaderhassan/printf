#include "main.h"

/**
 * print_ptr - Is a function that prints the value of a pointer
 * @val: list of arguments.
 *
 * Return: The number of characters printed (counter).
 */
int print_ptr(va_list val)
{
	void *p;
	char *s = "(nil)";
	long int x;
	int y;
	int i;

	p = va_arg(val, void*);
	if (p == NULL)
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			_putchar(s[i]);
		}
		return (i);
	}

	x = (unsigned long int)p;
	_putchar('0');
	_putchar('x');
	y = print_hexadec_extra(x);
	return (y + 2);
}
