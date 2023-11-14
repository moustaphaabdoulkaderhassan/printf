#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

// Enum to represent different types of format specifiers
typedef enum {
    FMT_LITERAL,
    FMT_INTEGER,
    FMT_UNSIGNED,
    FMT_OCTAL,
    FMT_HEX_LOWERCASE,
    FMT_HEX_UPPERCASE,
    FMT_STRING,
    FMT_CHAR
} FmtType;

// Struct to represent a part of the format specifier
typedef struct {
    FmtType type;
    union {
        int int_val;
        unsigned int unsigned_val;
        char *str_val;
        char char_val;
    };
} FmtPart;

// Printf function handling various conversion specifiers
int formatted_print(const char *format, ...);

// Functions for handling different format specifiers
void _print_digits(int num, int *count);
void _print_unsigned(unsigned int num, int *count);
void _print_octal(unsigned int num, int *count);
void _print_hex(unsigned int num, const char *hex_digits, int *count);
void _print_string(const char *s, int *count);
void _print_char(char c, int *count);

#endif
