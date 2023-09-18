#include "main.h"
/**
 * get_print - This function determines the appropriate
 * printing function based on the conversion specifier passed to  _printf.
 * @s: char that contains the convo specifier.
 * Description: The function iterates through an array of structs ( func_arr[] )
 * to find a match between the specifier passed to  _printf  and the first element
 *  of each struct. It then selects the appropriate printing function based on the match.
 * Return: A pointer to the printing function that matches the specified conversion specifier.
 */
int (*get_print(char s))(va_list, flags_t *)
{
	ph func_arr[] = {
		{'i', print_int},
		{'s', print_string},
		{'c', print_char},
		{'d', print_int},
		{'u', print_unsigned},
		{'x', print_hex},
		{'X', print_hex_big},
		{'b', print_binary},
		{'o', print_octal},
		{'R', print_rot13},
		{'r', print_rev},
		{'S', print_bigS},
		{'p', print_address},
		{'%', print_percent},
		{'y', handle_length_modifiers},
	};
	int flags = 15;

	register int i;

	for (i = 0; i < flags; i++)
		if (func_arr[i].c == s)
			return (func_arr[i].f);
	return (NULL);
}
