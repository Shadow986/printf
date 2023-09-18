#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * get_int - a function that retrieves an integer argument
 * @l: va_list parameter
 * @f: Pointer to flags_t structure
 * Return: Retrieved integer argument
 */
int get_int(va_list l, flags_t *f)
{
	return (va_arg(l, int));
}

/**
 * get_octal - a function that prints a number in octal format
 * @l: va_list parameter
 * @f: Pointer to flags_t structure
 * Return: Length of printed characters
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

	return (x + 1);
}

/**
 * get_hex - a function that prints a number in hexadecimal format
 * @l: va_list parameter
 * @f: Pointer to flags_t structure
 * Return: Length of printed characters
 */
int get_hex(va_list l, flags_t *f)
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

	return (x + 1);
}

/**
 * handle_length_modifiers - a function that handles length modifiers
 * for non-custom conversion specifiers
 * @l: va_list parameter
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

int main(void)
{
	int num = 42;

	printf("Print integer: %d\n", num);
	return (0);
}

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
