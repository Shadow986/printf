#include <stdarg.h>
#include <stdio.h>
#include "main.h"


/**
 * get_int - a function that prints an integer using get_printf.
 * @l: va_list parameter
 * @f: Pointer to flags_t structure
 * Return: Length of printed characters or -1 on error
 */
int get_int(va_list l, flags_t *f)
{
	return (get_printf(l, f));
}

/**
 * get_octal - a function that prints a number in octal format.
 * @l: va_list parameter (unused)
 * @f: Pointer to flags_t structure (unused)
 * Return: Length of printed characters or -1 on error
 */
int get_octal(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	unsigned int remainder;
	int x = 0;
	char octal_num[32] = {0};

	while (num != 0)
	{
		remainder = num % 8;
		num /= 8;
		octal_num[x++] = remainder + '0';
	}
	for (--x; x >= 0; x--)
	{
		putchar(octal_num[x]);
	}
	return (x);
}

/**
 * print_hex - a function that prints a number in hexadecimal format.
 * @l: va_list parameter (unused)
 * @f: Pointer to flags_t structure (unused)
 * Return: Length of printed characters or -1 on error
 */
int print_hex(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	unsigned int remainder;
	int x = 0;
	char hex_num[32] = {0};

	while (num != 0)
	{
		remainder = num % 16;
		num /= 16;
		hex_num[x++] = (remainder < 10) ? remainder + '0' : remainder - 10 + 'A';
	}
	for (--x; x >= 0; x--)
	{
		putchar(hex_num[x]);
	}
	return (x);
}

/**
 * handle_length_modifiers - a function that handles length
 * modifiers for non-custom conversion specifiers.
 * @l: va_list parameter (unused)
 * @f: Pointer to flags_t structure
 * Return: Length of printed characters or -1 on error
 */
int handle_length_modifiers(va_list l, flags_t *f)
{
	char c = *(f->fo);
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
			length = print_int(l, f);
			break;
		case 'u':
			length = print_uint(l, f);
			break;
		case 'o':
			length = print_octal(l, f);
			break;
		case 'x':
		case 'X':
			length = print_hex(l, f);
			break;
		default:
			return (-1);
	}
	return (length);
}

int main(void)
{
	int num = 42;

	printf("Print integer: %d\n", num);
	return (0);
}
