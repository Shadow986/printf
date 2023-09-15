#include "main.h"
/**
 * _strlen - strlen
 *@s: char pointer
 * Return: len
 */
int _strlen(char *s)
{
	char *copy_s = s;
	int length = 0;

	while (*copy_s != '\0')
	{
		length++;
		copy_s++;
	}
	return (length);
}