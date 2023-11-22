#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct type_format
{
	char	e;
	int	(*f)(va_list a);
}f_t;

int	_putchar(char c)
{
	return (write(1, &c, 1));
}

int	print_char(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}

int	print_string(va_list args)
{
	int	i;
	char *s;

	s = va_arg(args, char *);
	if (s == NULL)
		return (1); 
	for (i = 0; s[i]; i++)
		_putchar(s[i]);
	return(i);
}

/**
 * print_integer - function
*/
int	print_integer(va_list args)
{
	int	nb;
	int	n;
	int	length;
	int	value;
	int	unit;

	length = 0;
	value = va_arg(args, int);

	if (nb == 0)
	{
		_putchar('0');
		length++;
	}

	if (value < 0)
	{
		_putchar('-');
		n = value * -1;
		length++;
	}
	else
		n = value;

	nb = n;
	unit = 1;
	while (nb > 0)
	{
		nb /= 10;
		unit = unit * 10;
	}
	while (unit >= 1)
	{
		_putchar(((n / unit) % 10) + '0');
		unit = unit / 10;
		length++;
	}

	return (length);
}

int	print_mod(va_list args)
{
	(void)args;
	_putchar('%');
	return (1);
}

int	(*print_format(const char *format))(va_list)
{
	int	index;
	f_t	ft[] = {
			{'c', print_char},
			{'s', print_string},
			{'%', print_mod},
			{'d', print_integer},
			{'i', print_integer},
			{NULL, NULL},
		};

	for (index = 0; ft[index].e; index++)
	{
		if (*format == ft[index].e)
			return(ft[index].f);
	}
	return(ft[5].f);
}

int	_printf(const char *format, ...)
{
	int	length;
	int	i;
	va_list	args;
	int	(*f)(va_list);
	/*char	*c;*/

	i = 0;
	length = 0;

	/*c = malloc( length * size(const char *) + 1);*/

	va_start(args, format);
	if (format == NULL)		/* add !(format[i + 1]) ?? */
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

int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return (0);
}