#include "main.h"

/**
 * print_chr - prints a character.
 * @val: list of arguments.
 * Return: The number of characters printed
 */
int print_chr(va_list val)
{
	char s;

	s = va_arg(val, int);
	_putchar(s);
	return (1);
}
