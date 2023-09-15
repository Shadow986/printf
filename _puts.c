#include "main.h"
/**
 * _puts - func prints str
 * @str: char pointer
 * @k: counter thru str
 * Return: 0
 */
void _puts(char *str, int *k)
{
	if (!str)
	{
		_putchar('(', k);
		_putchar('n', k);
		_putchar('u', k);
		_putchar('l', k);
		_putchar('l', k);
		_putchar(')', k);
		return;
	}
	while (*str)
	{
		_putchar(*str, k);
		str++;
	}
}