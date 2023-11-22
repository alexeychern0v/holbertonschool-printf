#include "main.h"

/**
 * *print_fromat - that will verify each elements 
 * @format : elements to check
 * 
 * Return: pointer on function otherwise NULL
*/
int	(*print_format(const char *format))(va_list)
{
	int	index;
	f_t	ft[] = {
			{'c', print_char},
			{'s', print_string},
			{'%', print_mod},
			{'d', print_integer},
			{'i', print_integer},
			{'\0', NULL}
		};

	for (index = 0; ft[index].e; index++)
	{
		if (*format == ft[index].e)
			return(ft[index].f);
	}
	return(ft[5].f);
}
