#include "main.h"
/**
 * handle_write_char - prints a str
 * @c: char types.
 * @buffer: Buffer arr
 * @flags:  Calc flags.
 * @width: width.
 * @precision: precs specs
 * @size: size specs
 * Return: Num of chars
 */

int handle_write_char(char c, char buffer[],

int flags, int width, int precision, int size)

{ 

int i = 0;

char padd = ' ';



UNUSED(precision);

UNUSED(size);



if (flags & F_ZERO)

padd = '0';



buffer[i++] = c;

buffer[i] = '\0';



if (width > 1)

{

buffer[BUFF_SIZE - 1] = '\0';

for (i = 0; i < width - 1; i++)

buffer[BUFF_SIZE - i - 2] = padd;



if (flags & F_MINUS)

return (write(1, &buffer[0], 1) +

write(1, &buffer[BUFF_SIZE - i - 1], width - 1));

else

return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +

write(1, &buffer[0], 1));

}



return (write(1, &buffer[0], 1));

}

/**
 * write_number - prints a str
 * @is_negative: lista of args
 * @ind: char types.
 * @buffer: buffer arr
 * @flags:  calcflags
 * @width: width.
 * @precision: preci specs
 * @size: size specs
 * Return: Num of chars
 */

int write_number(int is_negative, int ind, char buffer[],

int flags, int width, int precision, int size)

{

int length = BUFF_SIZE - ind - 1;

char padd = ' ', extra_ch = 0;



UNUSED(size);



if ((flags & F_ZERO) && !(flags & F_MINUS))

padd = '0';

if (is_negative)

extra_ch = '-';

else if (flags & F_PLUS)

extra_ch = '+';

else if (flags & F_SPACE)

extra_ch = ' ';



return (write_num(ind, buffer, flags, width, precision,

length, padd, extra_ch));

}

/**
 * write_unsgnd - Writes an unsigned num
 * @is_negative: Number that indicates whether the num is negative.
 * @ind: At which index does the number initiate within the buffer?
 * @buffer: arr of chars
 * @flags: flags specs
 * @width: width specs
 * @precision: prec specs
 * @size: size specs
 * Return: Number of written chars.
 */

int write_unsgnd(int is_negative, int ind,

char buffer[],

int flags, int width, int precision, int size)

{



int length = BUFF_SIZE - ind - 1, i = 0;

char padd = ' ';



UNUSED(is_negative);

UNUSED(size);



if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')

return (0); 



if (precision > 0 && precision < length)

padd = ' ';



while (precision > length)

{

buffer[--ind] = '0';

length++;

}



if ((flags & F_ZERO) && !(flags & F_MINUS))

padd = '0';



if (width > length)

{

for (i = 0; i < width - length; i++)

buffer[i] = padd;



buffer[i] = '\0';



if (flags & F_MINUS) 

{

return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));

}

else

{

return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));

}

}



return (write(1, &buffer[ind], length));

}

/**
 * write_pointer - Write a memloc
 * @buffer: arr of chars
 * @ind: At what index does the num begin in the buffer?
 * @length: len of num
 * @width: width specs
 * @flags: Flags specs
 * @padd: char reping padding
 * @extra_c: char reping extra char
 * @padd_start: At which index should the padding begin?
 * Return: num of chars.
 */

int write_pointer(char buffer[], int ind, int length,

int width, int flags, char padd, char extra_c, int padd_start)

{

int i;



if (width > length)

{

for (i = 3; i < width - length + 3; i++)

buffer[i] = padd;

buffer[i] = '\0';

if (flags & F_MINUS && padd == ' ')

{

buffer[--ind] = 'x';

buffer[--ind] = '0';

if (extra_c)

buffer[--ind] = extra_c;

return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));

}

else if (!(flags & F_MINUS) && padd == ' ')

{

buffer[--ind] = 'x';

buffer[--ind] = '0';

if (extra_c)

buffer[--ind] = extra_c;

return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));

}

else if (!(flags & F_MINUS) && padd == '0')

{

if (extra_c)

buffer[--padd_start] = extra_c;

buffer[1] = '0';

buffer[2] = 'x';

return (write(1, &buffer[padd_start], i - padd_start) +

write(1, &buffer[ind], length - (1 - padd_start) - 2));

}

}

buffer[--ind] = 'x';

buffer[--ind] = '0';

if (extra_c)

buffer[--ind] = extra_c;

return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));

}