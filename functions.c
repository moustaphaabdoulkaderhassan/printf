#include "main.h"

/**
 *print_char - Writes a single character to the standard output
 *@c: Character to be printed
 */
void print_char(char c)
{
	write(1, &c, 1);
}

/**
 *print_str - Writes a null-terminated string to the standard output
 *@s: Pointer to the string to be printed
 */
void print_str(const char *s)
{
	for (const char *t = s; *t; t++)
	{
		write(1, t, 1);
	}
}

/**
 *print_unsigned - Writes an unsigned integer as a string
 *@num: Unsigned integer to be printed
 *@digits: Digits used for conversion (e.g., "0123456789")
 */
void print_unsigned(unsigned int num, const char *digits)
{
	char buf[32], *q = buf + sizeof(buf);
	*--q = '\0';

	do {
		*--q = digits[num % 10];
		num /= 10;
	} while (num > 0);

	write(1, q, buf + sizeof(buf) - q - 1);
}

/**
 *print_hex - Writes an unsigned integer in hexadecimal
 *@num: Unsigned integer to be printed
 *@hex_digits: Digits used for hexadecimal conversion
 */
void print_hex(unsigned int num, const char *hex_digits)
{
	char buf[32], *q = buf + sizeof(buf);
	*--q = '\0';

	do {
		*--q = hex_digits[num % 16];
		num /= 16;
	} while (num > 0);

	write(1, q, buf + sizeof(buf) - q - 1);
}
