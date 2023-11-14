#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* Constants */
#define BUFF_SIZE 1024

/* Flag definitions */
#define F_MINUS 1
#define F_PLUS  2
#define F_SPACE 4
#define F_HASH  8
#define F_ZERO  16

/* Size specifier definitions */
#define S_LONG 1
#define S_SHORT 2

/* Function prototypes */
int _printf(const char *format, ...);
int print_char(char c, char buffer[], int *buff_ind);
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size);
int handle_print(const char *format, int *i, va_list types, char buffer[],
                 int flags, int width, int precision, int size);
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list types);
int get_precision(const char *format, int *i, va_list types);
int get_size(const char *format, int *i);
void print_buffer(char buffer[], int *buff_ind);
int write_num(int ind, char buffer[], int flags, int width, int prec,
              int length, char padd, char extra_c);
int write_unsgnd(int is_negative, int ind, char buffer[],
                 int flags, int width, int precision, int size);
int write_pointer(char buffer[], int ind, int length,
                  int width, int flags, char padd, char extra_c, int padd_start);
int write_number(int is_negative, int ind, char buffer[],
                 int flags, int width, int precision, int size);
int write_non_printable(char buffer[], int ind, char *str,
                        int flags, int width, int precision, int size);
int write_reverse(char buffer[], int ind, char *str,
                  int flags, int width, int precision, int size);
int write_rot13string(char buffer[], int ind, char *str,
                      int flags, int width, int precision, int size);
int is_printable(char c);
int append_hexa_code(char ascii_code, char buffer[], int i);
int is_digit(char c);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */

