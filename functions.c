#include "main.h"

/**
 * print_char - function that print a character
 * @args: argument
 * 
*/
int	print_char(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}

/**
 * print_string - function that print a string
 * 
 * Return: the length of the string
*/
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
 * print_integer - function that print a integer
 * 
 * Return: size of the fucntion, otherwise 1
*/
int	print_integer(va_list args)
{
	int	nb;
	int	length;
	int	value;

	length = 0;
	nb = va_arg(args, int);

	if (nb < 0)
	{
		_putchar('-');
		nb = nb * -1;
		length++;
	}

	if (nb == 0)
	{
		_putchar('0');
		return (1);
	}

	while (nb != '\0')
	{
		value = nb % 10;
		_putchar(value + 48);
		nb = nb / 10;
		length++;
	}

	return (length);
}

/**
 * _pour100 - function that print character '%'
 * @args : given arguments
 * 
 * Return: character '%'
*/
int	print_mod(va_list args)
{
	(void)args;
	_putchar('%');
	return (1);
}
