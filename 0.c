#include "main.h"
/**
 *
 */

int _printf(const char *format, ...)
{
	va_list args;
	int lenght = 0;
	char *c;
	char *str;

	va_start(args, format);
	
	while (*format =! '\0')
	{
		c = va_arg(args, char *);
		while
			putchar(c);
		
		
		str = va_arg(args, char *);
		length = strlen(str);
		return (lenght);
		
		
		va_end(args);
}

