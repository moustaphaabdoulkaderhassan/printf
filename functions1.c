#include "main.h"

/**
 * _print_binary - Writes the binary representation of an unsigned integer to the standard output
 * @num: Unsigned integer to be printed in binary
 *
 * Return: void.
 */
void print_binary(unsigned int num)
{
	char buf[32], *q = buf + sizeof(buf);
	*--q = '\0';

	do {
		*--q = '0' + (num % 2);
		num /= 2;
	} while (num > 0);

	write(STDOUT_FILENO, q, buf + sizeof(buf) - q - 1);
}
