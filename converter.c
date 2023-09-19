#include "main.h"
/**
 * convert - This function converts a number and base
 * into a string representation
 * @num: input num
 * @base: input base
 * @lowercase: This flag specifies whether the hexadecimal
 * values should be in lowercase.
 * Return: str
 */
char *convert(unsigned long int num, int base, int lowercase)
{
	static char *rep;
	static char buffer[50];
	char *ptr;

	rep = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}
