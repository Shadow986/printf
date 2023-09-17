#include "main.h"
/**
 * get_flag - The function activates flags if  `_printf`
 * encounters a flag modifier in the format str.
 * @s: The char that contains flag specifier
 * @f: The pointer to the struct flags where the flags are enabled.
 * Return: 1 if a flag has been turned on, else 0
 */
int get_flag(char s, flags_t *f)
{
	int i = 0;

	switch (s)
	{
		case '+':
			f->plus = 1;
			i = 1;
			break;
		case ' ':
			f->space = 1;
			i = 1;
			break;
		case '#':
			f->hash = 1;
			i = 1;
			break;
	}

	return (i);
}
