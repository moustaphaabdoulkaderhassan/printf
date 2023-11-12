#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int print_chr(char c);
int print_str(const char *str);
int print_binry(unsigned int num);
int print_int(int num);

#endif
