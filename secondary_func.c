#include "main.h"
/**
 * print_pointer - prints the value of a ptr var
 * @types: list of args
 * @buffer: buffer arr
 * @flags: calc flags
 * @width: width
 * @precision: prec specs
 * @size: size specs
 * Return: num of chars
 */
int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char extra_c = 0, padd = ' ';
int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
unsigned long num_addrs;
char map_to[] = "0123456789abcdef";
void *addrs = va_arg(types, void *);
UNUSED(width);
UNUSED(size);
if (addrs == NULL)
return (write(1, "NULL", 4));
buffer[BUFF_SIZE - 1] = '\0';
UNUSED(precision);
num_addrs = (unsigned long)addrs;
while (num_addrs > 0)
{
buffer[ind--] = map_to[num_addrs % 16];
num_addrs /= 16;
length++;
}
if ((flags & F_ZERO) && !(flags & F_MINUS))
padd = '0';
if (flags & F_PLUS)
extra_c = '+', length++;
else if (flags & F_SPACE)
extra_c = ' ', length++;
ind++;

return (write_pointer(buffer, ind, length,
width, flags, padd, extra_c, padd_start));
}