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



Explanation for printf.c file
1- File: printf.c

Prototype: int _printf(const char format, ...);*

Description:
- Implements a custom version of the C standard printf function.
- Processes a format string and prints output according to the detected format specifiers.
Uses variadic functions (va_list, va_start, va_arg) to handle multiple arguments dynamically.

How it works:

Validates input:
- Returns -1 if format is NULL or contains only a single % with no specifier.
- Iterates through the format string character by character.
- When a normal character is found:
- It is printed directly using _putchar.

When a % is found:
- Moves to the next character to detect the specifier.

Handles the following formats:
- %c  → Prints a single character using _putchar.
- %s  → Prints a full string using print_string.
- %%  → Prints a literal percent sign (%).
- %d / %i → Prints an integer using print_number.

For unknown specifiers:
- Prints % then prints the unknown character.
- Keeps track of printed characters using the count variable.
- Uses va_end to properly close variadic argument handling.

Returns:
- Total number of characters printed.
- Returns -1 for invalid input formats.
