#include "main.h"

/**
 * print_char - function that print a character
 * @args: argument
 *
 * Return: 1 on success
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
 * Description : this function take in argument a string and print it
 *		by using a index named i, in a loop.
 * @args : argument
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
 * print_integer - function that print a integer
 * Description : this function print digit wither its a int or decimal
 *		its take a argument as parameter
 * @args : argument, number to print
 *
 * Return: size of the fucntion, otherwise 1§
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
	while (nb > 9)
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

/**
 * print_mod - function that print character '%'
 * @args : given arguments
 *
 * Return: character '%'
*/
int	print_mod(va_list args)
{
	(void)args;
	return (_putchar('%'));
}
