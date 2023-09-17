#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_format - a function that prints formatted output
 * @format: the format to print
 * @args: variable argument list
 * Return: the count of characters printed
 */

int print_format(const char *format, va_list args)
{
	int count = 0;
	unsigned int num;
	int x;

	for (x = 0; format[x] != '\0'; x++)
	{
		if (format[x] == '%')
		{
			x++;
			switch (format[x])
			{
				case 'u':
					num = va_arg(args, unsigned int);
					break;
				case 'o':
					num = va_arg(args, unsigned int);
					break;
				case 'x':
					num = va_arg(args, unsigned int);
					break;
				case 'X':
					num = va_arg(args, unsigned int);
					break;
				default:
					return (-1);
			}
		}
		else
		{
		}
	}
	return (count);
}
