#include "main.h"
/**
 * print_string - loops thru a str & prints every char
 * @l: va_list args from _printf
 * @f: pointer to the struct flags
 * Return: num of char
 */
int print_string(va_list l, flags_t *f)
{
	char *s = va_arg(l, char *);

	(void)f;

	if (!s)
		s = "(null)";
	return (_puts(s));
}
/**
 * print_char - prints a char
 * @l: va_list args from _printf
 * @f: pointer to the struct flags
 * Return: num of char
 */
int print_char(va_list l, flags_t *f)
{
	(void)f;
	_putchar(va_arg(l, int));
	return (1);
}