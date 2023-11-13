#include "main.h"

/**
 * print_chr - prints a character
 * Returns: The number of characters printed
 */
int print_chr(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_str - Prints a string.
 * Return: Number of characters printed.
 */
int print_str(const char *str)
{
	int n = 0;

	while (*str)
	{
		n += write(1, str++, 1);
	}

	return (n);
}

/**
 * print_binry - is a function that Prints an unsigned number.
 * Return: The numbers of characters printed.
 */
int print_binry(unsigned int num)
{
	char buffer[32];
	int bit = 0;

	for (bit = 31; bit >= 0; bit--)
	{
		buffer[31 - bit] = ((num >> bit) & 1) + '0';
	}

	return (write(1, buffer, 32));
}

/**
 * print_int - prints an integer
 * Return: Number of chars printed
 */
int print_int(int num)
{
	int n = 0;
	int i = 0;
	int temp = num;
	char buffer[12];
	int chrs_printed = 0;

	if (num < 0)
	{
		n += print_chr('-');
		num = -num;
		chrs_printed++;
	}

	while (temp > 0)
	{
		temp /= 10;
		chrs_printed++;
	}

	if (chrs_printed == 0)
	{
		chrs_printed++;
	}

	i = chrs_printed - 1;
	while (i >= 0 && i--)
	{
		buffer[chrs_printed - 1 - i] = (num % 10) + '0';
		num /= 10;
	}

	n += write(1, buffer, chrs_printed);

	return (n);
}
