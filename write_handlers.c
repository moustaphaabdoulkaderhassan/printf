#include "main.h"

/*************************WRITE HANDLEERS *************************/
/**
 *handle_write_char - Prints a character
 *@c: Is the Character types
 *@buffer: Is The Buffer array to handle print
 *@flags:  Calculates active flags
 *@width: Is the Width specifier
 *@precision: is the precision specifier
 *@size: is the size specifier
 *
 *Return: Number of characters printed.
 */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[i] = '\0';
		for (i = 1; i < width; i++)
			buffer[i] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
				write(1, &buffer[1], width - 1));
		else
			return (write(1, &buffer[1], width - 1) +
				write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**********************WRITEs NUMBER *************************/
/**
 *write_number - Prints a number
 *@is_negative: is the flag indicating if the number is negative
 *@ind: Index at which the number starts in the buffer
 *@buffer: Is the buffer array to handle print
 *@flags:  Calculates active flags
 *@width: Is the width specifier
 *@precision: is the precision specifier
 *@size: is the size specifier
 *
 *Return: Number of characters printed.
 */
int write_number(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = BUFFER_SIZE - ind - 1;
	char padd = ' ', extra_c = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_c = '-';
	else if (flags & F_PLUS)
		extra_c = '+';
	else if (flags & F_SPACE)
		extra_c = ' ';

	return (write_num(ind, buffer, flags, width, precision,
				length, padd, extra_c));
}

/**
 *write_num - Writes a number using the buffer
 *@ind: is the index at which the number starts in the buffer
 *@buffer: Buffer array to handle print
 *@flags:  Calculates active flags
 *@width: is the width specifier
 *@prec: is the precision specifier
 *@length: the numb length
 *@padd: is the padding character
 *@extra_c: is the Extra character
 *
 *Return: Number of characters printed.
 */
int write_num(int ind, char buffer[], int flags, int width, int prec,
	int length, char padd, char extra_c)
{
	int i, padd_start = 0;

	if (prec == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;
		buffer[ind] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 *write_unsgnd - Writes an unsigned number
 *@is_negative: Number indicating if the num is negative
 *@ind: is the Index at which the number starts in the buffer
 *@buffer: is the Buffer array to handle print
 *@flags: is the Flags specifier
 *@width: is the Width specifier
 *@precision: is the Precision specifier
 *@size: is the Size specifier
 *
 *Return: Number of written characters.
 */
int write_unsgnd(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFFER_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;

		buffer[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/**
 *write_pointer - Writes a memory address
 *@buffer: Arrays of chars
 *@ind: is the Index at which the number starts in the buffer
 *@length: is the number lenght
 *@width: is the width specifier
 *@flags: is the Flags specifier
 *@padd: Character representing the padding
 *@extra_c: Character representing extra char
 *@padd_start: is the index at which padding should start.
 *
 *Return: Number of written Characters.
 */
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}

	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFFER_SIZE - ind - 1));
}
