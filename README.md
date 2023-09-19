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

# secondary_func

1. The function  print_pointer  takes a variable argument list ( types ) and other parameters ( buffer ,  flags ,  width ,  precision ,  size ). It retrieves a pointer value from the variable argument list using  va_arg  and performs operations to convert and print the pointer. It converts the pointer value to a hexadecimal representation, handles flags and padding, and calls the  write_pointer  function to print the pointer. The function returns the number of characters printed. 
 
2. The function  print_non_printable  takes a variable argument list ( types ) and other parameters ( buffer ,  flags ,  width ,  precision ,  size ). It retrieves a string from the variable argument list using  va_arg  and performs operations to print non-printable characters in a hexadecimal format. It checks each character in the string using the  is_printable  function and appends the appropriate hexadecimal code to the buffer. The function then writes the contents of the buffer to the standard output and returns the number of characters printed. 
 
3. The function  print_reverse  takes a variable argument list ( types ) and other parameters ( buffer ,  flags ,  width ,  precision ,  size ). It retrieves a string from the variable argument list using  va_arg  and prints the string in reverse order. The function iterates over the characters in the string, starting from the last character, and writes them to the standard output. It returns the number of characters printed. 
 
4. The function  print_rot13string  takes a variable argument list ( types ) and other parameters ( buffer ,  flags ,  width ,  precision ,  size ). It retrieves a string from the variable argument list using  va_arg  and performs a ROT13 encryption on the string. It replaces each character in the string with the corresponding ROT13 character and writes the resulting string to the standard output. The function returns the number of characters printed. 
 
Each of these functions follows a similar pattern of retrieving data from the variable argument list, performing necessary operations, and writing the result to the standard output.

# get_flags

1. The code includes the "main.h" header file, which likely contains necessary declarations and definitions for the code to work. 
 
2. The function  get_flags  takes two parameters:  format , which is the formatted string in which to print the arguments, and  i , which is a pointer to an integer. The function returns an integer representing the calculated flags. 
 
3. Inside the function, there are several variables declared:  j  and  curr_i  of type  int , and  flags  of type  int . There is also a constant character array  FLAGS_CH  containing the characters that represent the flags ('-', '+', '0', '#', ' '), and a corresponding constant integer array  FLAGS_ARR  containing the flag values (F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0). 
 
4. The function uses a nested loop structure to iterate through the characters of the  format  string. The outer loop iterates from the current value of  *i + 1  until the end of the string ( format[curr_i] != '\0' ). 
 
5. Inside the outer loop, there is an inner loop that iterates through the  FLAGS_CH  array. It checks if the current character ( format[curr_i] ) matches any of the flag characters ( FLAGS_CH[j] ). 
 
6. If a match is found, the corresponding flag value ( FLAGS_ARR[j] ) is bitwise ORed with the  flags  variable. This sets the corresponding flag bit to 1. 
 
7. After the inner loop, there is an additional check to see if the inner loop reached the end of the  FLAGS_CH  array ( FLAGS_CH[j] == 0 ). If so, it breaks out of the outer loop as well. 
 
8. Finally, the value of  curr_i - 1  is assigned to  *i . This updates the value of  i  to the current position in the  format  string. 
 
9. The function returns the calculated  flags . 
 
In summary, the  get_flags  function scans a formatted string and identifies the active flags by comparing the characters in the string with a predefined set of flag characters. It sets the corresponding flag bits in the  flags  variable and returns the calculated flags.

# print_prec

1. The code includes the "main.h" header file, which likely contains necessary declarations and definitions for the code to work. 
 
2. The function  get_precision  takes three parameters:  format , which is the formatted string in which to print the arguments,  i , which is a pointer to an integer, and  list , which is a list of arguments. 
 
3. The function calculates and returns the precision for printing based on the provided format string. 
 
4. Inside the function, there are several variables declared:  curr_i  and  precision  of type  int . 
 
5. The function checks if the character immediately following the current position ( format[curr_i] ) is a period ('.'). If it is not, the function returns the default precision value of -1. 
 
6. If the character is a period, the function sets the initial value of  precision  to 0. 
 
7. The function then enters a loop that iterates through the characters of the  format  string, starting from the position after the period. 
 
8. Inside the loop, the function checks if the current character is a digit using the  is_digit  function. If it is, the function updates the value of  precision  by multiplying it by 10 and adding the numerical value of the current digit. 
 
9. If the current character is an asterisk ('*'), the function increments  curr_i  to skip the asterisk character and retrieves the precision value from the  list  using  va_arg . It then breaks out of the loop. 
 
10. If the current character is neither a digit nor an asterisk, the function breaks out of the loop. 
 
11. Finally, the value of  curr_i - 1  is assigned to  *i . This updates the value of  i  to the current position in the  format  string. 
 
12. The function returns the calculated  precision . 
 
In summary, the  get_precision  function calculates the precision for printing based on the provided format string. It checks if the format string contains a period, and if so, it iterates through the characters after the period to determine the precision value. The precision can be either a specified numerical value or retrieved from the argument list using an asterisk. The function returns the calculated precision value.

# print_size

1. The code includes the "main.h" header file, which likely contains necessary declarations and definitions for the code to work. 
 
2. The function  get_size  takes two parameters:  format , which is the formatted string in which to print the arguments, and  i , which is a pointer to an integer. 
 
3. The function calculates and returns the size to cast the argument based on the provided format string. 
 
4. Inside the function, there are several variables declared:  curr_i  and  size  of type  int . 
 
5. The function checks the character immediately following the current position ( format[curr_i] ) to determine the size of the argument. 
 
6. If the character is 'l', the function sets the value of  size  to  S_LONG , which likely represents a long size. 
 
7. If the character is 'h', the function sets the value of  size  to  S_SHORT , which likely represents a short size. 
 
8. If the value of  size  remains 0, it means that there is no specific size specified in the format string. In this case, the function updates the value of  *i  to the current position in the  format  string minus 1. 
 
9. If a specific size is found, the function updates the value of  *i  to the current position in the  format  string. 
 
10. Finally, the function returns the calculated  size . 
 
In summary, the  get_size  function calculates the size to cast the argument based on the provided format string. It checks the characters following the current position in the format string and determines the size based on the presence of 'l' or 'h'. The function returns the calculated size value, which can be  S_LONG ,  S_SHORT , or 0 if no specific size is specified

# print_width

1. The code includes the "main.h" header file, which likely contains necessary declarations and definitions for the code to work. 
 
2. The function  get_width  takes three parameters:  format , which is the formatted string in which to print the arguments,  i , which is a pointer to an integer, and  list , which is a list of arguments. 
 
3. The function calculates and returns the width for printing based on the provided format string. 
 
4. Inside the function, there are several variables declared:  curr_i  and  width  of type  int . 
 
5. The function uses a loop to iterate through the characters of the  format  string, starting from the position after the current value of  *i . 
 
6. Inside the loop, the function checks if the current character is a digit using the  is_digit  function. If it is, the function updates the value of  width  by multiplying it by 10 and adding the numerical value of the current digit. 
 
7. If the current character is an asterisk ('*'), the function increments  curr_i  to skip the asterisk character and retrieves the width value from the  list  using  va_arg . It then breaks out of the loop. 
 
8. If the current character is neither a digit nor an asterisk, the function breaks out of the loop. 
 
9. Finally, the value of  curr_i - 1  is assigned to  *i . This updates the value of  i  to the current position in the  format  string. 
 
10. The function returns the calculated  width . 
 
In summary, the  get_width  function calculates the width for printing based on the provided format string. It iterates through the characters after the current position in the format string and determines the width value. The width can be either a specified numerical value or retrieved from the argument list using an asterisk. The function returns the calculated width value.