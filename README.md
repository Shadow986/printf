# printf_version 3.0

improved printf function

# write_func

1. The code includes the "main.h" header file, which likely contains necessary declarations and definitions for the code to work. 
 
2. The code defines the function  handle_write_char , which takes several parameters ( c ,  buffer ,  flags ,  width ,  precision ,  size ) and is responsible for printing a single character. The function first checks if the  F_ZERO  flag is set, and assigns the padding character accordingly. It then places the character at the beginning of the  buffer  array and adds padding characters to the right of it, based on the  width  parameter. Finally, it writes the contents of the  buffer  array to the standard output and returns the number of characters printed. 
 
3. The code defines the function  write_number , which takes similar parameters as  handle_write_char  and is responsible for printing a number. It first determines if the number is negative and assigns an extra character ( - ,  + , or space) accordingly. Then, it calls the function  write_num  to handle the actual printing of the number. 
 
4. The code defines the function  write_num , which is called by  write_number  and  write_pointer . This function takes several parameters ( ind ,  buffer ,  flags ,  width ,  prec ,  length ,  padd ,  extra_c ) and is responsible for printing a number using a buffer. It handles various cases such as precision, padding, and extra characters. The function builds the number representation in the  buffer  array and writes it to the standard output. 
 
5. The code defines the function  write_unsgnd , which is responsible for printing an unsigned number. It follows a similar logic to  write_number , but with some differences in handling precision and padding. 
 
6. The code defines the function  write_pointer , which is responsible for printing a memory address. It takes several parameters ( buffer ,  ind ,  length ,  width ,  flags ,  padd ,  extra_c ,  padd_start ) and builds the memory address representation in the  buffer  array. It handles padding, extra characters, and the  F_MINUS  flag. 

# main_func

1. The function  print_char  takes a variable argument list ( types ) and other parameters ( buffer ,  flags ,  width ,  precision ,  size ). It retrieves a character from the variable argument list using  va_arg  and calls the  handle_write_char  function to print the character. The function then returns the number of characters printed. 
 
2. The function  print_string  also takes a variable argument list ( types ) and other parameters ( buffer ,  flags ,  width ,  precision ,  size ). It retrieves a string from the variable argument list using  va_arg  and performs various operations on the string. It calculates the length of the string, handles precision and width, and writes the modified string to the standard output. The function returns the number of characters printed. 
 
3. The function  print_percent  takes a variable argument list ( types ) and other parameters ( buffer ,  flags ,  width ,  precision ,  size ). It simply writes a percent sign ( % ) to the standard output and returns the number of characters printed. 
 
4. The function  print_int  takes a variable argument list ( types ) and other parameters ( buffer ,  flags ,  width ,  precision ,  size ). It retrieves an integer from the variable argument list using  va_arg  and performs operations to convert and print the integer. It handles negative integers, converts the integer to a string representation, and calls the  write_number  function to print the number. The function returns the number of characters printed. 
 
5. The function  print_binary  takes a variable argument list ( types ) and other parameters ( buffer ,  flags ,  width ,  precision ,  size ). It retrieves an unsigned integer from the variable argument list using  va_arg  and converts it to binary representation. It then writes the binary representation to the standard output and returns the number of characters printed. 
 
Each of these functions is responsible for printing a specific type of data and follows a similar pattern of retrieving data from the variable argument list, performing necessary operations, and writing the result to the standard output.

# primary_func

1. The function  print_unsigned  takes a variable argument list ( types ) and other parameters ( buffer ,  flags ,  width ,  precision ,  size ). It retrieves an unsigned long integer from the variable argument list using  va_arg  and performs operations to convert and print the number. It converts the number to a string representation, calls the  write_unsgnd  function to print the number, and returns the number of characters printed. 
 
2. The function  print_octal  takes a variable argument list ( types ) and other parameters ( buffer ,  flags ,  width ,  precision ,  size ). It retrieves an unsigned long integer from the variable argument list using  va_arg  and converts it to octal notation. It then calls the  write_unsgnd  function to print the octal number and returns the number of characters printed. If the  F_HASH  flag is set and the initial number is not zero, it adds a leading '0' to the output. 
 
3. The function  print_hexadecimal  takes a variable argument list ( types ) and other parameters ( buffer ,  flags ,  width ,  precision ,  size ). It retrieves an unsigned long integer from the variable argument list using  va_arg  and converts it to hexadecimal notation using lowercase letters. It calls the  print_hexa  function with the appropriate mapping array and returns the number of characters printed. 
 
4. The function  print_hexa_upper  takes a variable argument list ( types ) and other parameters ( buffer ,  flags ,  width ,  precision ,  size ). It retrieves an unsigned long integer from the variable argument list using  va_arg  and converts it to hexadecimal notation using uppercase letters. It calls the  print_hexa  function with the appropriate mapping array and returns the number of characters printed. 
 
5. The function  print_hexa  takes a variable argument list ( types ), a mapping array ( map_to ), and other parameters ( buffer ,  flags ,  flag_ch ,  width ,  precision ,  size ). It retrieves an unsigned long integer from the variable argument list using  va_arg  and converts it to hexadecimal notation using the given mapping array. It calls the  write_unsgnd  function to print the hexadecimal number and returns the number of characters printed. If the  F_HASH  flag is set and the initial number is not zero, it adds a leading  flag_ch  (either 'x' or 'X') and '0' to the output. 
 
Each of these functions follows a similar pattern of retrieving an unsigned number from the variable argument list, converting it to the desired notation, and then calling the  write_unsgnd  function to handle the printing

