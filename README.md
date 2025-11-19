Explination for functions.c file

1- File: _putchar.c
Prototype: int _putchar(char c);

Description:

- Writes a single character to standard output (stdout).
- Uses the system call write(1, &c, 1) for direct byte-level output.

- Returns:
1 on success
-1 on error
- Acts as the fundamental output unit for all higher-level printing functions.

2- File: print_string.c
Prototype: int print_string(char *str);

Description:

- Prints an entire string one character at a time using _putchar.

- Safely handles NULL by printing the literal string "(NULL)".

- Returns the total number of characters printed.

- Used for implementing the %s conversion specifier in _printf.

3- File: print_number.c
Prototype: int print_number(int n);

Description:

- Prints an integer using only _putchar.
- Handles:
Positive numbers
Negative numbers (prints a - sign first)
- Uses recursion to print digits from most significant to least significant.
- Converts integers to characters using '0' + (digit).
- Returns the number of printed characters.
- Used for numeric conversion specifiers in _printf.
