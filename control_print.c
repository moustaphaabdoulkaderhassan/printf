#include "main.h"

/**
 * control_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: index.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: gets width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: (1) or (2)
 */
int control_print(const char *fmt, int *ind, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int i, unknown_len = 0, chrs_printed = -1;
	fmt_t arr[] = {
		{'c', print_chr}, {'s', print_str}, {'%', print_cent},
		{'i', print_interger}, {'d', print_interger}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_oct}, {'x', print_hexadec},
		{'X', print_upper_hex}, {'p', print_ptr}, {'S', print_non_print},
		{'r', print_rev}, {'R', print_rot13str}, {'\0', NULL}
	};

	for (i = 0; arr[i].fmt != '\0'; i++)
		if (fmt[*ind] == arr[i].fmt)
			return (arr[i].fn(list, buffer, flags, width, precision, size));

	if (arr[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknown_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknown_len += write(1, " ", 1);
		else if (width)
		{ --(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}

		unknown_len += write(1, &fmt[*ind], 1);
		return (unknown_len);
	}

	return (chrs_printed);
}
