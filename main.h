#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

typedef struct {
    char fmt;
    int (*fn)(va_list, char[], int, int, int, int);
} fmt_t;

int print_char(va_list kinds, char buffer[], int flags, int width, int precision, int size);
int print_string(va_list kinds, char buffer[], int flags, int width, int precision, int size);
int print_percent(va_list kinds, char buffer[], int flags, int width, int precision, int size);
int print_int(va_list kinds, char buffer[], int flags, int width, int precision, int size);
int print_binary(va_list kinds, char buffer[], int flags, int width, int precision, int size);
int print_hexa_upper(va_list kinds, char buffer[], int flags, int width, int precision, int size);
int print_pointer(va_list kinds, char buffer[], int flags, int width, int precision, int size);
int print_non_printable(va_list kinds, char buffer[], int flags, int width, int precision, int size);

long int convert_size_unsigned(unsigned long int num, int size);
long int convert_size_num(long int num, int size);
int is_printable(char c);

#endif /* MAIN_H */
