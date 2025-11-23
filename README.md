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

Flowchart functions.c file

 +-------------------------------------+
|        Start _printf()              |
+------------------+------------------+
                   |
                   v
+-------------------------------------+
|  Is format NULL ?                   |
+------------------+------------------+
         | Yes                | No
         v                    v
+---------------+   +-----------------------------+
| return -1     |   | Loop through format string  |
+---------------+   +-------------+---------------+
                                  |
                                  v
                    +-----------------------------+
                    | Is current char != '%' ?    |
                    +-------------+---------------+
                                  | Yes
                                  v
                    +-----------------------------+
                    | Print char directly         |
                    | count++                     |
                    +-------------+---------------+
                                  |
                                  v
                           Next character
                                  |
                                  v
                    +-----------------------------+
                    | Found '%' ?                 |
                    +-------------+---------------+
                                  | Yes
                                  v
       +------------------+------------------+------------------+
       | %c               | %s               | %%               |
       v                  v                  v
+-------------+  +----------------+  +-----------------------+
| print char  |  | print string   |  | print '%'            |
| count++     |  | count += len   |  | count++              |
+-------------+  +----------------+  +-----------------------+

                                  |
                                  v
                           Next character
                                  |
                                  v
+---------------------------------------------+
| Reached end of format ?                     |
+------------------+--------------------------+
                   |
                   v
       +-------------------------------+
       | return count                  |
       +-------------------------------+


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

Flowchart printf.c file

+-------------------------------------+
|        Start _printf()              |
+------------------+------------------+
                   |
                   v
( Same steps as Task 0 until '%' is found )
                   |
                   v
+-------------------------------------+
|  Is specifier 'd' or 'i' ?          |
+------------------+------------------+
         | Yes                | No → go back to Task 0 cases
         v
+---------------------------------------------+
|  Get integer using va_arg                   |
+---------------------------------------------+
                   |
                   v
+---------------------------------------------+
|  If number < 0 : print '-' and invert num   |
+---------------------------------------------+
                   |
                   v
+---------------------------------------------+
| Convert number to digits (loop or recursion)|
+---------------------------------------------+
                   |
                   v
+---------------------------------------------+
| Print each digit                            |
| count += number_of_digits                   |
+---------------------------------------------+
                   |
                   v
            Return to main loop
                   |
                   v
+---------------------------------------------+
| End of format ? → return count              |
+---------------------------------------------+




Explanation (for man_3_printf)

The _printf function is a custom implementation of the standard C printf function, developed as part of the Holberton School curriculum. Its primary purpose is to format and print text to the standard output (stdout) using a limited set of conversion specifiers. While it mimics the behavior of the standard printf, it deliberately supports only a restricted subset of features to help students understand low-level output handling, variadic functions, and string parsing.

The function processes the format string one character at a time:

Ordinary characters are written directly to the output using the _putchar function.

Format specifiers, which begin with the % character, trigger special formatting behavior. Each supported specifier is handled by a dedicated helper function:

- %c prints a single character using _putchar.
- %s prints a string using print_string, handling NULL pointers safely.
- %d and %i print signed decimal integers using print_number.
- %% prints a literal percent sign.

Unlike the standard library printf, this _printf does not support advanced features such as flags (+, -, 0, #, space), field width, precision, or length modifiers (h, l, etc.). Its behavior focuses solely on correctly processing the basic specifiers and validating proper format syntax.

If the function encounters a NULL format string or an incomplete specifier (e.g., a trailing %), it returns -1 to indicate an error. Otherwise, it returns the total number of characters printed, excluding the terminating null byte.

Flowchart for man_3_printf

+----------------------------------------+
|               _printf()                |
+-------------------+--------------------+
                    |
                    v
+----------------------------------------+
| Is format NULL ?                        |
+-------------------+--------------------+
       | Yes                      | No
       v                          v
+--------------+        +---------------------------+
| return -1    |        | Start parsing format      |
+--------------+        +-------------+-------------+
                                     |
                                     v
                   +--------------------------------+
                   | Is current char != '%' ?        |
                   +-------------+--------------------+
                                 | Yes
                                 v
                   +--------------------------------+
                   | Print char directly             |
                   | count++                         |
                   +-------------+--------------------+
                                 |
                                 v
                          Next character
                                 |
                                 v
                   +--------------------------------+
                   | Found '%' ?                    |
                   +-------------+------------------+
                                 | Yes
                                 v
       +------------------+------------------+-------------------+
       |   %c             |    %s            |      %%           |
       v                  v                  v
+-------------+  +----------------+  +---------------------------+
| print char  |  | print string   |  | print '%'                |
| count++     |  | count += len   |  | count++                  |
+-------------+  +----------------+  +---------------------------+

                                 |
                                 v
                          Continue parsing
                                 |
                                 v
+------------------------------------------------+
| End of string reached → return total count     |
+------------------------------------------------+


