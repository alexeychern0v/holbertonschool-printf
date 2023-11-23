#include "main.h"

/**
 * print_char - function that print a character
 * @args: argument list
 *
 * Return: char
*/
int	print_char(va_list args)
{
	char	c;

	c = va_arg(args, int);
	_putchar(c);
	return (1);
}

/**
 * print_string - function that print a string
 * @args : argument list
 *
 * Return: the length of the string
*/
int	print_string(va_list args)
{
	int	i;
	char *s;

	s = va_arg(args, char *);

	if (s == NULL)
		s = "(null)";

	for (i = 0; s[i]; i++)
		_putchar(s[i]);
	return (i);
}

/**
 * print_integer - function that print digit (d or i)
 * @args : argument list
 *
 * Return: number of character printed
*/
int	print_integer(va_list args)
{
	int	nb;
	int	n;
	int	length;
	int	unit;

	length = 0;
	nb = va_arg(args, int);

	if (!nb)
		return (-1);

	if (nb < 0)
	{
		length += _putchar('-');
		nb *= -1;
	}

	if (nb <= 9)
	{
		length += _putchar(nb + '0');
		return (length);
	}

	n = nb;
	unit = 1;
	while (n > 9)
	{
		n /= 10;
		unit = unit * 10;
	}
	while (unit >= 1)
	{
		_putchar(((nb / unit) % 10) + '0');
		unit /= 10;
		length++;
	}

	return (length);
}

/**
 * print_mod - function that print character '%'
 * @args : arguments list
 *
 * Return: character '%'
*/
int	print_mod(va_list args)
{
	(void)args;
	return (_putchar('%'));
}
