#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

/**
 * _printf - Custom printf function
 */
int _printf(const char *format, ...);

/**
 * control_print - Prints an argument based on its type
 */
int control_print(const char *fmt, int *i, va_list list, char buffer[],
		int flags, int width, int precision, int size);

/****************** THE FUNCTIONS ******************/

/* Functions to print characters and strings */
int print_chr(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_str(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_cent(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* Functions to print numbers too */
int print_interger(va_list types, char buffer[],
                   int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
                 int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_oct(va_list types, char buffer[],
              int flags, int width, int precision, int size);
int print_hexadec(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_upper_hex(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hex(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size);

/* Function to print non-printable characters too */
int print_non_print(va_list types, char buffer[],
                    int flags, int width, int precision, int size);

/* Function to print memory address too */
int print_ptr(va_list types, char buffer[],
              int flags, int width, int precision, int size);

/* Functions handling other specifiers */
int fetch_flags(const char *format, int *i);
int fetch_width(const char *format, int *i, va_list list);
int fetch_precision(const char *format, int *i, va_list list);
int fetch_size(const char *format, int *i);

/* Function to print THE string in reverse */
int print_rev(va_list types, char buffer[],
              int flags, int width, int precision, int size);

/* Function to print THE string in rot 13 */
int print_rot13str(va_list types, char buffer[],
                   int flags, int width, int precision, int size);

/* WRITE handler */
int handle_write_char(char c, char buffer[],
                      int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
                 int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
              int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
                  int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
                 char buffer[],
                 int flags, int width, int precision, int size);

/****************** UTILITYS ******************/
int is_printable(char);
int append_hex_code(char, char[], int);
int is_dig(char);

long int convert_size_num(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif
