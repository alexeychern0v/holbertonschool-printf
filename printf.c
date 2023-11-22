#include "main.h"

/**
 * _printf - function that produces output according to a format
 * @format : string
 * 
 * Return: number of char printer
*/
int	_printf(const char *format, ...)
{
	int	length;
	int	i;
	va_list	args;
	int	(*f)(va_list);

	va_start(args, format);

	i = 0;
	length = 0;
	if (format == NULL)
		return (-1);
	while (format && format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			f = print_format(&format[i + 1]);
			if (f == NULL)
				return (-1);
			length += f(args);
			i++;
		}
		else
		{
			length += _putchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (length);
}
