#include"main.h"
#include <unistd.h>
/**
 * _putchar - writes the char stdout
 * @c: char printed
 * @k: counter thru str
 * Return: 1 = success, else -1
 */
int _putchar(char c, int *k)
{
	*k += 1;
		return (write(1, &c, 1));
}
