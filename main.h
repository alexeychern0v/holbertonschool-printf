#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct type_format
{
	char	e;
	int	(*f)(va_list a);
}f_t;

int _printf(const char *format, ...);
int	(*print_format(const char *format))(va_list);
int	print_char(va_list args);
int	print_string(va_list args);
int	print_dec(va_list args);
int	print_integer(va_list args);
int	print_mod(va_list args);

#endif
