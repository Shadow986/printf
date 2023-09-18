#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * handle_precision - a function that handles the
 * precision for non-custom conversion specifiers
 * @l: va_list parameter
 * @f: Pointer to flags_t structure
 * Return: Length of printed characters or -1 on error
 */
int handle_precision(va_list l, flags_t *f)
{
	char c = *(f->fo);
	int precision = 0;
	int length = 0;

	switch (c)
	{
		case 'l':
			f->l_modifier = 1;
			break;
		case 'h':
			f->h_modifier = 1;
			break;
		default:
			return (-1);
	}

	f->fo++;
	c = *(f->fo);

	switch (c)
	{
		case 'd':
		case 'i':
			precision = va_arg(l, int);
			length = get_int(l, f);
			break;
		case 'u':
			precision = va_arg(l, int);
			length = get_uint(l, f);
			break;
		case 'o':
			precision = va_arg(l, int);
			length = get_octal(l, f);
			break;
		case 'x':
		case 'X':
			precision = va_arg(l, int);
			length = get_hex(l, f);
			break;
		default:
			return (-1);
	}

	if (precision > length)
		length = precision;

	return (length);
}
