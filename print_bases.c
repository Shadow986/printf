#include "main.h"
/**
 * print_hex - number in hex base,in lowercase
 * @l: va_list args from _printf
 * @f: pointer to the struct flags
 * Description: The function invokes the  `convert()`  function, which in turn converts the input number to the appropriate base and returns it as a string.
 * Return: num of char
 */
int print_hex(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = convert(num, 16, 1);
	int count = 0;

	if (f->hash == 1 && str[0] != '0')
		count += _puts("0x");
	count += _puts(str);
	return (count);
}
/**
 * print_hex_big - number in hex base,in uppercase
 * @l: va_list args from _printf
 * @f: pointer to the struct flag
 * Description: The function invokes the  `convert()`  function, which in turn converts the input number to the appropriate base and returns it as a string.
 * Return: num of char
 */
int print_hex_big(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = convert(num, 16, 0);
	int count = 0;

	if (f->hash == 1 && str[0] != '0')
		count += _puts("0X");
	count += _puts(str);
	return (count);
}
/**
 * print_binary - number in base 2
 * @l: va_list args from _printf
 * @f: pointer to the struct flag
 * Description: The function invokes the  `convert()`  function, which in turn converts the input number to the appropriate base and returns it as a string.g
 * Return: num of char
 */
int print_binary(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = convert(num, 2, 0);

	(void)f;
	return (_puts(str));
}
/**
 * print_octal - number printed in base 8
 * @l: va_list args from _printf
 * @f: pointer to the struct flag
 * Description: The function invokes the  `convert()`  function, which in turn converts the input number to the appropriate base and returns it as a string.
 * Return: num of char
 */
int print_octal(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = convert(num, 8, 0);
	int count = 0;

	if (f->hash == 1 && str[0] != '0')
		count += _putchar('0');
	count += _puts(str);
	return (count);
}