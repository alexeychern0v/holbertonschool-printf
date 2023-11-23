#include "main.h"

/**
 * _printf - function that produces output according to a format
 * @format : string
 *
 * Return: number of character printed
*/
int	_printf(const char *format, ...)
{
	int	length;
	int	i;
	va_list	args;
	int	(*f)(va_list);

	i = 0;
	va_start(args, format);
	if (format == NULL || !format[i + 1])
		return (-1);

	length = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			f = print_format(&format[i + 1]);
			
			if (f == NULL)
			{
				length += _putchar(format[i]);
				length += _putchar(format[i + 1]);
			}
			else
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
