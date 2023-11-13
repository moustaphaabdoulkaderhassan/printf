#include "main.h"

/**
 *handle_chr_write - Prints a string
 *@c: character types.
 *@buffer: Buffer array to handle print
 *@flags:  Calculates active flags.
 *@width: gets the width.
 *@precision: The precision specifier
 *@size: The size specifier
 *
 *Return: Number of characters printed.
 */
int handle_chr_write(char c, char buffer[],
	int flags, int width, int precision, int size)
{ /*character is stored at the left and paddind at buffer's right */
	int i = 0;
	char padd_chr = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd_chr = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFFER_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFFER_SIZE - i - 2] = padd_chr;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
				write(1, &buffer[BUFFER_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFFER_SIZE - i - 1], width - 1) +
				write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}


/**
 *write_number - Prints a string
 *@is_negative: Lista of arguments
 *@index: character types.
 *@buffer: Buffer array to handle print
 *@flags:  Calculates active flags
 *@width: get width.
 *@precision: precision specifier
 *@size: Size specifier
 *
 *Return: Number of chars printed.
 */
int write_number(int is_negative, int index, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFFER_SIZE - index - 1;
	char padd_chr = ' ', extra_chr = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd_chr = '0';
	if (is_negative)
		extra_chr = '-';
	else if (flags & F_PLUS)
		extra_chr = '+';
	else if (flags & F_SPACE)
		extra_chr = ' ';

	return (write_num(index, buffer, flags, width, precision,
		length, padd_chr, extra_chr));
}

/**
 *write_num - Writes a number using a bufffer
 *@index: where the number starts on the buffer
 *@buffer: Buffer array
 *@flags: handles Flags
 *@width: Gets width
 *@prec: The precision specifier
 *@length: Number of the length
 *@padd_chr: Pading character
 *@extra_char: Extra character
 *
 *Return: Number of printed characters.
 */
int write_num(int index, char buffer[],
	int flags, int width, int prec,
	int length, char padd_chr, char extra_char)
{
	int i, padd_chr_start = 1;

	if (prec == 0 && index == BUFFER_SIZE - 2 && buffer[index] == '0' && width == 0)
		return (0);   /*printf(".0d", 0)  no character is printed */
	if (prec == 0 && index == BUFFER_SIZE - 2 && buffer[index] == '0')
		buffer[index] = padd_chr = ' ';
	if (prec > 0 && prec < length)
		padd_chr = ' ';
	while (prec > length)
		buffer[--index] = '0', length++;
	if (extra_char != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd_chr;
		buffer[i] = '\0';
		if (flags &F_MINUS && padd_chr == ' ') /*Asign extra char to left of buffer */
		{
			if (extra_char)
				buffer[--index] = extra_char;
			return (write(1, &buffer[index], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd_chr == ' ') /*extra char to left of buff */
		{
			if (extra_char)
				buffer[--index] = extra_char;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[index], length));
		}
		else if (!(flags & F_MINUS) && padd_chr == '0') /*extra char to left of padd */
		{
			if (extra_char)
				buffer[--padd_chr_start] = extra_char;
			return (write(1, &buffer[padd_chr_start], i - padd_chr_start) +
				write(1, &buffer[index], length - (1 - padd_chr_start)));
		}
	}

	if (extra_char)
		buffer[--index] = extra_char;
	return (write(1, &buffer[index], length));
}

/**
 *write_unsignd - Writes an unsigned number
 *@is_negative: Number indicating if the num is negative
 *@index: Index at which the number starts in the buffer
 *@buffer: is the array of chars
 *@flags: is a flags specifiers
 *@width: is a Width specifier
 *@precision: the precision specifier
 *@size: The size specifier
 *
 *Return: Number of written characters.
 */
int write_unsignd(int is_negative, int index, char buffer[], int flags, int width, int precision, int size)
{
	/*The number is stored at the bufer's right and starts at position i */
	int length = BUFFER_SIZE - index - 1, i = 0;
	char padd_chr = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && index == BUFFER_SIZE - 2 && buffer[index] == '0')
		return (0); /*printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < length)
		padd_chr = ' ';

	while (precision > length)
	{
		buffer[--index] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd_chr = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd_chr;

		buffer[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[index], length) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[index], length));
		}
	}

	return (write(1, &buffer[index], length));
}

/**
 *write_ptr - Write a memory address
 *@buffer: Arrays of characterss
 *@index: Index at which the number starts in the buffer
 *@length: The Length of the number
 *@width: get Width
 *@flags: Flags specifier
 *@padd_chr: character representing the padding
 *@extra_char: character representing extra char
 *@padd_start: Index at which padding should start
 *
 *Return: Number of written characters.
 */
int write_ptr(char buffer[], int index, int length,
	int width, int flags, char padd_chr, char extra_char, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd_chr;
		buffer[i] = '\0';
		if (flags &F_MINUS && padd_chr == ' ') /*Asign extra char to left of buffer */
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extra_char)
				buffer[--index] = extra_char;
			return (write(1, &buffer[index], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd_chr == ' ') /*extra char to left of buffer */
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extra_char)
				buffer[--index] = extra_char;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[index], length));
		}
		else if (!(flags & F_MINUS) && padd_chr == '0')
		{
			if (extra_char)
				buffer[--padd_start] = extra_char;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[index], length - (1 - padd_start) - 2));
		}
	}

	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (extra_char)
		buffer[--index] = extra_char;
	return (write(1, &buffer[index], BUFFER_SIZE - index - 1));
}
