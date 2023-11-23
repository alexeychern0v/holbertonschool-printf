#include "main.h"

/**
 * *print_format - search for the correct function to execute
 * @format : character to check for the corresponding format
 *
 * Return: pointer on function
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
			return (ft[index].f);
	}
	return (ft[5].f);
}
