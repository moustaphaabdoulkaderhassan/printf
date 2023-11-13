#include "main.h"

/**
 *print_chr - Prints a character
 *@kinds: List of arguments
 *@buffer: The Buffer array to control print
 *@flags:  Calculates active flags
 *@width: Is the Width
 *@precision: Is  the Precision specification
 *@size: The Size specifier
 *Return: Number of characters printed
 */
int print_chr(va_list kinds, char buffer[], int flags, int width, int precision, int size)
{
	char c = va_arg(kinds, int);

	return (handle_chr_write(c, buffer, flags, width, precision, size));
}


/**
 *print_str - Prints a string
 *@kinds: List a of arguments
 *@buffer: Is the Buffer array to control print
 *@flags:  Calculates active flags
 *@width: gets width.
 *@precision: Is the Precision specification
 *@size: is the Size specifier
 *Return: Number of characters printed
 */
int print_str(va_list kinds, char buffer[], int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *input_str = va_arg(kinds, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (input_str == NULL)
	{
		input_str = "(null)";
		if (precision >= 6)
			input_str = "      ";
	}

	while (input_str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &input_str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &input_str[0], length);
			return (width);
		}
	}

	return (write(1, input_str, length));
}


/**
 *print_percent - Prints a percent sign
 *@kinds: Lista of arguments
 *@buffer: Buffer array to handle print
 *@flags:  Calculates active flags
 *@width: gets width.
 *@precision: The Precision specification
 *@size: The Size specifier
 *Return: Number of characters printed
 */
int print_percent(va_list kinds, char buffer[], int flags, int width, int precision, int size)
{
	UNUSED(kinds);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}


/**
 *print_integer - Prints an int
 *@kinds: Lista of arguments
 *@buffer: Buffer array to handle print
 *@flags:  Calculates active flags
 *@width: gets width.
 *@precision: The precision specification
 *@size: The Size specifier
 *Return: Number of characters printed
 */
int print_integer(va_list kinds, char buffer[], int flags, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	int is_negative = 0;
	unsigned long int num;
	long int n = va_arg(kinds, long int);
	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';
	num = (unsigned long int) n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}


/**
 *print_binry - a function that prints an unsigned number
 *@kinds: Lista of arguments
 *@buffer: Buffer array to handle print
 *@flags:  Calculates active flags
 *@width: get width.
 *@precision: Precision specification
 *@size: Size specifier
 *Return: Numbers of char printed.
 */
int print_binry(va_list kinds, char buffer[], int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(kinds, unsigned int);
	m = 2147483648; /*(2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}

	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}

	return (count);
}
