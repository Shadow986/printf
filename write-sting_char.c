#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _myprintf - a function that produces output according to a format
 * @format: character string (to be printed)
 * @args: variable argument list
 * Return: the number of characters printed (excluding the null byte)
 */

int _myprintf(const char *format, va_list args)
{
	int count = 0;
	char *str;
	char c;
	int x, y;

	for (x = 0; format[x] != '\0'; x++)
	{
		if (format[x] == '%')
		{
			x++;
			switch (format[x])
			{
				case 'c':
					c = (char)va_arg(args, int);
					write(1, &c, 1);
					count++;
					break;
				case 's':
					str = va_arg(args, char *);
					for (y = 0; str[y] != '\0'; y++)
					{
						write(1, &str[y], 1);
						count++;
					}
					break;
				case '%':
					write(1, &format[x], 1);
					count++;
					break;
				default:
					return (-1);
			}
		}
		else
		{
			write(1, &format[x], 1);
			count++;
		}
	}
	return (count);
}
