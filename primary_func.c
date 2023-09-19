#include "main.h"
/**
 * print_unsigned - print unsigned int
 * @types: list of args
 * @buffer: buffer arr
 * @flags:  calc flags
 * @width: width
 * @precision: prec specs
 * @size: size specs
 * Return: num of chars
 */

int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
num = convert_size_unsgnd(num, size);
if (num == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buffer[i--] = (num % 10) + '0';
num /= 10;
}
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/**
 * print_octal - print an unsigned int in octal notation
 * @types: lista of args
 * @buffer: buffer arr
 * @flags:  calc flags
 * @width: width
 * @precision: prec specs
 * @size: size specs
 * Return: num of chars
 */
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;
UNUSED(width);
num = convert_size_unsgnd(num, size);
if (num == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buffer[i--] = (num % 8) + '0';
num /= 8;
}
if (flags & F_HASH && init_num != 0)
buffer[i--] = '0';
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - prints an unsigned num in hex notation
 * @types: lista of args
 * @buffer: buffer arr
 * @flags:  calc flags
 * @width: width
 * @precision: prec specs
 * @size: size specs
 * Return: num of chars
 */
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789abcdef", buffer,
flags, 'x', width, precision, size));
}
/**
 * print_hexa_upper - prints unsigned num in upper hex notation
 * @types: lista of args
 * @buffer: buffer arr
 * @flags:  calc flags
 * @width: width
 * @precision: prec specs
 * @size: size specs
 * Return: num of chars
 */
int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789ABCDEF", buffer,
flags, 'X', width, precision, size));
}

/**
 * print_hexa - print a hex num in upper or lower
 * @types: list of args
 * @map_to: arr of val
 * @buffer: buffer arr
 * @flags:  calc flags
 * @flag_ch: calc flags
 * @width: width
 * @precision: prec specs
 * @size: size specs
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;
UNUSED(width);
num = convert_size_unsgnd(num, size);
if (num == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buffer[i--] = map_to[num % 16];
num /= 16;
}
if (flags & F_HASH && init_num != 0)
{
buffer[i--] = flag_ch;
buffer[i--] = '0';
}
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}