#include "main.h"
/**
 * print_address - This function prints the hexadecimal format of the input address.
 * @l: va_list args from _printf
 * @f: pointer to the struct flags
 * Return: num of char
 */
int print_address(va_list l, flags_t *f)
{
	char *str;
	unsigned long int p = va_arg(l, unsigned long int);

	register int count = 0;

	(void)f;

	if (!p)
		return (_puts("(nil)"));
	str = convert(p, 16, 1);
	count += _puts("0x");
	count += _puts(str);
	return (count);
}