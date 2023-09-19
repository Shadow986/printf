#include "main.h"
/**
 * print_char - print a char
 * @types: list of args
 * @buffer: buffer arr
 * @flags:  Calc flags
 * @width: width
 * @precision: prec specs
 * @size: size specs
 * Return: Num of chars
 */
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char c = va_arg(types, int);
return (handle_write_char(c, buffer, flags, width, precision, size));
}