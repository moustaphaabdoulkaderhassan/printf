#include "main.h"

/**
 * is_dig - Verifies if a character is a digit
 * @c: Character to be checked
 *
 * Return: (1) if c is a digit, (0) otherwise
 */
int is_dig(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}
