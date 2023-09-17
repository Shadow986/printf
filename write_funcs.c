#include "main.h"
#include <unistd.h>
/**
 * _putchar - char c to stdout
 * @c: a char
 * Return: On success 1. else -1
 * Description: _putchar utils buffer of 1024 to minimize usage of write
 */
int _putchar(char c)
{
	static char buf[1024];
	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, &buf, i);
		i = 0;
	}
	if (c != -1)
	{
		buf[i] = c;
		i++;
	}
	return (1);
}
/**
 * _puts - prints str to stdout
 * @str: ptr to the str
 * Return: num of chars
 */
int _puts(char *str)
{
	register int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}
