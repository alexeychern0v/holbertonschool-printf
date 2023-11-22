#include "main.h"
/**
 * _printf - printf ourselves
 */

int _printf(const char *format, ...)
{
	va_list args;
	int lenght = 0;
	char *c;
	char *str;
	int number;

	va_start(args, format);
	
	while (*format =! '\0')
	{
	    if (*format == '%')
	    {
	        format++;
	        if (*format == 'c') // if format is char
	        {
	            c = va_arg(args, char *);
	            print_char(va_list args)
	            length = 1;
	        }
	        else if (*format == 's') // if format is string
	        {
	            str = va_arg(args, char *);
	            print_string(va_list args);
	            length = strlen(str);
	            return (lenght);
	        }
	        else if (*format == 'i' || *format == 'd') // if int or double
	        {
	            number = va_arg(args, int);
	            print_integer(va_list args);
	            length = (int)log10(number) + 1; // lenght of int or d using log
	        }
	        else if (*format == '%')
	        {
	            print_mod(va_list args)
	            length = 1;
	        }
	    }
	    format++;
		
		va_end(args);
		
		return (length);
}

