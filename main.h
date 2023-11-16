#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>



/**
 * struct format - converter for the printf function
 * @ph: type character pointer of the specifier
 *
 * @function: function for the conversion specifier
 *
 */

typedef struct format
{
	char *ph;
	int (*function)();
} convert;

int *_strcpy(char *dest, char *src);
int print_ptr(va_list val);
int print_unsgnd(va_list args);
int print_hexadec_extra(unsigned long int num);
int _strlenc(const char *s);
int print_hexa_extra(unsigned int num);
int print_exc_str(va_list val);
int print_hexa(va_list val);
int print_hexadec(va_list val);
int print_oct(va_list val);
int print_binry(va_list val);
int print_rev(va_list args);
int print_rot13str(va_list args);
int print_integer(va_list args);
int print_decimal(va_list args);
int _strlen(char *s);
int rev_string(char *s);
int print_cent(void);
int print_chr(va_list val);
int print_str(va_list val);
int _putchar(char c);
int _printf(const char *format, ...);
int fetch_width(const char *format, int *i, va_list list);
int is_dig(char c);

#endif
