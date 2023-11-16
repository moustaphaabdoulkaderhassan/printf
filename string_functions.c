#include "main.h"

/**
 * _strlen - is a function that finds the lenght of a string.
 * @s: is the string
 *
 * Return: The number of characters printed (integer).
 */

int _strlen(char *s)
{
	int c;

	for (c = 0; s[c] != 0; c++)
		;
	return (c);

}

/**
 * _strlenc - Finds the length of a string but for constant characters
 * @s: is the string
 * Return: the number of characters printed (integer).
 */

int _strlenc(const char *s)
{
	int c;

	for (c = 0; s[c] != 0; c++)
		;
	return (c);
}
