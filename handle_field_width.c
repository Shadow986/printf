#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * handle_field_width - a function that handles the field width
 * for non-custom conversion specifiers
 * @l: va_list parameter
 * @f: Pointer to flags_t structure
 * Return: The number of characters printed
 */
int handle_field_width(va_list l, flags_t *f)
{
	int width = 0;
	int num_chars = 0;
	int i = 0;

	if (f->fo[i] == '*')
	{
		width = va_arg(l, int);
		i++;
	}
	else
	{
		while (f->fo[i] >= '0' && f->fo[i] <= '9')
		{
			width = (width * 10) + (f->fo[i] - '0');
			i++;
		}
	}

	switch (f->fo[i])
	{
		case 'd':
		case 'i':
		case 'u':
		case 'o':
		case 'x':
		case 'X':
			num_chars += handle_integer(f->fo[i], width, l);
			break;
		default:
			num_chars += putchar('%');
			num_chars += putchar(f->fo[i]);
			break;
	}

	return (num_chars);
}
