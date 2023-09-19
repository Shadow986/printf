#include "main.h"



/**
 * is_printable - evals if a char is printable
 * @c: char eval
 * Return: 1 if c is printable, 0 otherwise
 */

int is_printable(char c)

{

if (c >= 32 && c < 127)

return (1);



return (0);

}

/**
 * append_hexa_code - app ascci in hex code to buffer
 * @buffer: arr of chars.
 * @i: appending index
 * @ascii_code: Ascii code.
 * Return: 3
 */

int append_hexa_code(char ascii_code, char buffer[], int i)

{

char map_to[] = "0123456789ABCDEF";

if (ascii_code < 0)

ascii_code *= -1;



buffer[i++] = '\\';

buffer[i++] = 'x';



buffer[i++] = map_to[ascii_code / 16];

buffer[i] = map_to[ascii_code % 16];



return (3);

}



/**
 * is_digit - verify if a char is a digit
 * @c: char eval
 * Return: 1 if c is a digit, else 0
 */

int is_digit(char c)

{

if (c >= '0' && c <= '9')

return (1);



return (0);

}