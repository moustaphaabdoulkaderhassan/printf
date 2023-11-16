#include "main.h"

/**
 * print_revs - function that prints a str in reverse
 * @args: type struct va_arg is where printed arguments are located
 *
 * Return: The string printed
 */
int print_rev(va_list args)
{

	char *s = va_arg(args, char*);
	int i;
	int j = 0;

	if (s == NULL)
		s = "(null)";
	while (s[j] != '\0')
		j++;
	for (i = j - 1; i >= 0; i--)
		_putchar(s[i]);
	return (j);
}
