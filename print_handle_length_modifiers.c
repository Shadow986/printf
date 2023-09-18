#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_length_modifiers - a function that handles length
 * modifiers for non-custom conversion specifiers.
 * @l: va_list parameter (unused)
 * @f: Pointer to flags_t structure
 * Return: Length of printed characters or -1 on error
 */
int handle_length_modifiers(va_list l, flags_t *f)
{
	char c = *(f->format);
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
	f->format++;
	c = *(f->format);
	switch (c)
	{
		case 'd':
		case 'i':
			length = get_int(l, f);
			break;
		case 'u':
			length = get_uint(l, f);
			break;
		case 'o':
			length = get_octal(l, f);
			break;
		case 'x':
		case 'X':
			length = get_hex(l, f);
			break;
		default:
			return (-1);
	}
	return (length);
}
