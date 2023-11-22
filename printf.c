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

	i = 0;
	length = 0;

	va_start(args, format);
	if (format == NULL)
	{
		return (-1);
	}

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
			_putchar(format[i]);
			length++;
		}
		i++;
	}
	va_end(args);

	return (length);
}
