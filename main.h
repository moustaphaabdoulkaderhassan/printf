#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>

#define BUFFER_SIZE 1024
#define UNUSED(x) (void)(x)

/* Flag constants */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* Size Definitions */
#define S_SHORT 1
#define S_LONG 2

/* Unused Macro to suppress warnings */
#define UNUSED(x) (void)(x)

/**
 * Struct definition for conversion specifiers
 */
typedef struct conversion_specifier
{
    char specifier;
    int (*function)(va_list, char[], int, int, int, int);
} specifier_t;


int _printf(const char *format, ...);
int control_print(const char *format, int *i, va_list list, char buffer[], int flags, int width, int precision, int size);

/* My functions.c */
int print_chr(va_list kinds, char buffer[], int flags, int width, int precision, int size);
int print_str(va_list kinds, char buffer[], int flags, int width, int precision, int size);
int print_percent(va_list kinds, char buffer[], int flags, int width, int precision, int size);
int print_int(va_list kinds, char buffer[], int flags, int width, int precision, int size);
int print_binary(va_list kinds, char buffer[], int flags, int width, int precision, int size);
int print_int(va_list kinds, char buffer[], int flags, int width, int precision, int size);


/* Output_handling.c */
int handle_chr_write(char c, char buffer[], int flags, int width, int precision, int size);
int write_number(int is_negative, int index, char buffer[], int flags, int width, int precision, int size);
int write_num(int index, char buffer[], int flags, int width, int prec, int length, char padd_chr, char extra_char);
int write_unsignd(int is_negative, int index, char buffer[], int flags, int width, int precision, int size);
int write_ptr(char buffer[], int index, int length, int width, int flags, char padd_chr, char extra_char, int padd_start);

/* flag sorting */
int fetch_flags(const char *format, int *i);
int fetch_precision(const char *format, int *i, va_list list);
int fetch_size(const char *format, int *i);
int fetch_width(const char *format, int *i, va_list list);

/* Utilitys */
int is_digit(char c);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif
