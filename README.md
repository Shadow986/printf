# printf_proto-type
improved printf function

# Write_func

This code defines two functions,  `_putchar`  and  `_puts` .

The  `_putchar`  function takes a single character as an argument and writes it to standard output (stdout). It uses a static buffer of 1024 characters to minimize the number of calls to the  `write`  system call. If the buffer is full or the character  `-1`  is passed as an argument, the function flushes the buffer by calling  `write`  with the buffer and its current size as arguments. The function returns  `1`  on success and  `-1`  on error.

The  `_puts`  function takes a pointer to a null-terminated string as an argument and writes the string to standard output using the  `_putchar`  function. It returns the number of characters written.

Both functions rely on the  `write`  system call, which is defined in the  `unistd.h`  header file. The  `main.h`  header file is included, but its contents are not shown in this code snippet.

# print_num

This code defines several functions related to printing integers.

The  `print_int`  function takes a variable argument list  `l`  and a pointer to a struct  `flags_t`  as arguments. It retrieves an integer from the variable argument list using  `va_arg` . It then determines the number of digits in the integer using the  `count_digit`  function. 

Based on the flags stored in the  `flags_t`  struct, the function may print a space character, a plus character, or increment the result count. It finally calls the  `print_number`  function to print the integer and returns the result count.

The  `print_unsigned`  function is similar to  `print_int` , but it is used for printing unsigned integers. It retrieves an unsigned integer from the variable argument list using  `va_arg`  and converts it to a string using the  `convert`  function. It then calls  `_puts`  to print the string representation of the unsigned integer and returns the number of characters printed.

The  `print_number`  function is a helper function that recursively prints each digit of an integer. It first checks if the integer is negative and prints a minus sign if necessary. It then recursively divides the absolute value of the integer by 10 and calls itself until there are no more digits left. Finally, it prints the last digit by adding the ASCII value of '0' to the remainder of the division.

The  `count_digit`  function calculates the number of digits in an integer. It first checks if the integer is negative and takes its absolute value. It then divides the absolute value by 10 in a loop until it becomes zero, incrementing a counter variable  `d`  with each iteration. The function returns the value of  `d` , which represents the number of digits in the integer.

# print_custom

This code defines several functions related to printing special characters and strings in different formats.

The  `print_bigS`  function is used for printing non-printable characters. It takes a variable argument list  `l`  and a pointer to a struct  `flags_t`  as arguments. It retrieves a string from the variable argument list using  `va_arg` . If the string is  `NULL` , it prints  `(null)`  and returns the number of characters printed. Otherwise, it iterates through each character of the string. If the character is a non-printable character (ASCII value less than 32 or greater than or equal to 127), it prints  `\x`  followed by the ASCII code value in hexadecimal. It uses the  `convert`  function to convert the ASCII code to a hexadecimal string representation and prints it. If the character is a printable character, it simply prints the character. The function returns the total number of characters printed.

The  `print_rev`  function is used for printing a string in reverse. It takes a variable argument list  `l`  and a pointer to a struct  `flags_t`  as arguments. It retrieves a string from the variable argument list using  `va_arg` . If the string is  `NULL` , it assigns  `"(null)"`  to the string. It then calculates the length of the string by iterating through it. Finally, it iterates through the string in reverse order and prints each character. The function returns the length of the printed string.

The  `print_rot13`  function is used for printing a string using the ROT13 cipher. It takes a variable argument list  `l`  and a pointer to a struct  `flags_t`  as arguments. It retrieves a string from the variable argument list using  `va_arg` . It then iterates through each character of the string. If the character is not a letter, it prints the character as it is. If the character is a letter, it finds the corresponding character in the ROT13 cipher and prints it. The function returns the number of characters printed.

The  `print_percent`  function is used for printing a percent symbol. It takes a variable argument list  `l`  and a pointer to a struct  `flags_t`  as arguments. It simply prints the percent symbol and returns the number of characters printed.

# print_bases

This code defines several functions related to printing numbers in different bases.

The  `print_hex`  function is used for printing a number in hexadecimal base, in lowercase. It takes a variable argument list  `l`  and a pointer to a struct  `flags_t`  as arguments. It retrieves an unsigned integer from the variable argument list using  `va_arg` . It then converts the number to a hexadecimal string representation using the  `convert`  function. If the  `hash`  flag is set and the string representation does not start with '0', it prints "0x" to indicate that it is a hexadecimal number. Finally, it prints the hexadecimal string and returns the number of characters printed.

The  `print_hex_big`  function is similar to  `print_hex` , but it prints the hexadecimal number in uppercase. It follows the same steps as  `print_hex` , but it uses the  `convert`  function with the  `lower`  argument set to 0 to convert the number to uppercase hexadecimal.

The  `print_binary`  function is used for printing a number in binary base. It takes a variable argument list  `l`  and a pointer to a struct  `flags_t`  as arguments. It retrieves an unsigned integer from the variable argument list using  `va_arg` . It then converts the number to a binary string representation using the  `convert`  function with the base argument set to 2. It simply prints the binary string and returns the number of characters printed.

The  `print_octal`  function is used for printing a number in octal base. It takes a variable argument list  `l`  and a pointer to a struct  `flags_t`  as arguments. It retrieves an unsigned integer from the variable argument list using  `va_arg` . It then converts the number to an octal string representation using the  `convert`  function with the base argument set to 8. If the  `hash`  flag is set and the string representation does not start with '0', it prints a single '0' to indicate that it is an octal number. Finally, it prints the octal string and returns the number of characters printed.

# print_alpha

This code defines two functions related to printing characters and strings.

The  `print_string`  function is used for printing a string. It takes a variable argument list  `l`  and a pointer to a struct  `flags_t`  as arguments. It retrieves a string from the variable argument list using  `va_arg` . If the string is  `NULL` , it assigns  `"(null)"`  to the string. It then calls the  `_puts`  function to print the string and returns the number of characters printed.

The  `print_char`  function is used for printing a character. It takes a variable argument list  `l`  and a pointer to a struct  `flags_t`  as arguments. It retrieves a character from the variable argument list using  `va_arg`  and calls the  `_putchar`  function to print the character. It returns  `1`  to indicate that one character has been printed.

# print_address

This code defines a function  `print_address`  that is used to print the address of a variable in hexadecimal format.

The function takes a variable argument list  `l`  and a pointer to a struct  `flags_t`  as arguments. It retrieves an unsigned long integer from the variable argument list using  `va_arg` .

If the value of the integer is zero (null), the function prints  `"(nil)"`  and returns the number of characters printed.

Otherwise, the function converts the integer to a hexadecimal string representation using the  `convert`  function with the base argument set to 16. It then prints  `"0x"`  to indicate that it is a hexadecimal address, followed by the hexadecimal string.

Finally, the function returns the total number of characters printed.

# converter

This code defines a function  `convert`  that is used to convert a number into a string representation in a specified base.

The function takes three arguments:  `num`  (the input number to be converted),  `base`  (the base in which the number should be converted), and  `lowercase`  (a flag indicating whether the hexadecimal values should be lowercase or uppercase).

The function starts by declaring a static character pointer  `rep`  and a static character array  `buffer`  of size 50.  `rep`  is set to a string representation of the digits in the specified base, either lowercase or uppercase based on the  `lowercase`  flag.

A pointer  `ptr`  is then declared and initialized to point to the last element of the  `buffer`  array. The last element is set to the null character to terminate the string.

The function enters a loop where it repeatedly divides the  `num`  by the  `base`  and uses the remainder to index into the  `rep`  string. The character at the corresponding index is then placed in the  `buffer`  array using the  `ptr`  pointer. The  `ptr`  is decremented to point to the previous element in the  `buffer`  array.

The loop continues until the  `num`  becomes zero. At this point, the  `ptr`  will be pointing to the first element of the converted string.

Finally, the function returns the  `ptr` , which now points to the string representation of the converted number.

# get_flag

This code defines a function  `get_flag`  that is used to turn on flags in a struct based on a flag specifier found in the format string of the  `_printf`  function.

The function takes two arguments:  `s`  (a character that holds the flag specifier) and  `f`  (a pointer to the struct  `flags_t`  in which the flags are turned on).

The function uses a  `switch`  statement to check the value of  `s`  and perform different actions based on its value.

- If  `s`  is  `'+'` , the function sets the  `plus`  flag in the  `flags_t`  struct to 1 and assigns 1 to the variable  `i` .
- If  `s`  is  `' '` , the function sets the  `space`  flag in the  `flags_t`  struct to 1 and assigns 1 to the variable  `i` .
- If  `s`  is  `'#'` , the function sets the  `hash`  flag in the  `flags_t`  struct to 1 and assigns 1 to the variable  `i` .

Finally, the function returns the value of  `i` , which indicates whether a flag has been turned on (1) or not (0).

# get_print

This code defines a function  `get_print`  that is used to select the appropriate printing function based on the conversion specifier passed to the  `_printf`  function.

The function takes a character  `s`  as an argument, which holds the conversion specifier.

It declares an array of structs  `func_arr`  named  `ph` , which consists of characters representing the conversion specifiers and function pointers to the corresponding printing functions.

The function then initializes the  `func_arr`  array with the appropriate conversion specifiers and their corresponding printing functions.

It declares an integer variable  `flags`  and assigns the number of elements in the  `func_arr`  array to it.

The function enters a loop that iterates through the  `func_arr`  array. It checks if the character  `s`  matches the conversion specifier in each struct. If a match is found, it returns the corresponding printing function.

If no match is found after looping through all the elements in the  `func_arr`  array, the function returns  `NULL`  to indicate that no appropriate printing function was found.

In summary, the  `get_print`  function matches the conversion specifier passed to  `_printf`  with the appropriate printing function and returns a pointer to that function.

# printf

This code defines the  `_printf`  function, which is used to produce formatted output according to a given format string.

The function takes a format string as its argument. It also uses the  `va_list`  type to handle variable arguments.

The function initializes a pointer  `p`  to point to the beginning of the format string. It also declares a  `flags_t`  struct named  `flags`  to keep track of any flags specified in the format string.

The function initializes a counter variable  `count`  to keep track of the number of characters printed.

It starts by checking if the format string is  `NULL`  or if it consists of only a single '%' character. In these cases, it returns -1.

It then enters a loop that iterates through each character in the format string. If the current character is '%', it checks if the next character is also '%'. If it is, it simply prints a '%' character and continues to the next iteration of the loop.

If the next character is not '%', it checks for any flags that may be specified after the '%'. It calls the  `get_flag`  function to turn on the appropriate flags in the  `flags`  struct.

It then calls the  `get_print`  function to determine the appropriate printing function based on the conversion specifier. It passes the  `va_list`  and  `flags`  struct as arguments to the printing function, and adds the return value of the printing function to the  `count`  variable.

If the current character is not '%', it simply prints the character using the  `_putchar`  function and increments the  `count`  variable.

After the loop ends, the function calls  `_putchar`  with the argument  `-1`  to flush any remaining characters in the buffer.

Finally, it ends by cleaning up the  `va_list`  and returns the total count of characters printed.