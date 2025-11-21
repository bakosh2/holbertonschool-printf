#include "main.h"
#include <unistd.h>
/**
 * _putchar - writes a character to stdout
 * @c: character to print
 *
 * Return: 1 on success
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - prints a string
 * @str: string to print
 *
 * Return: number of characters printed
*/
int print_string(char *str)
{
	int count = 0;

	if (!str)
		str = "(null)";

	while (*str)
		count += _putchar(*str++);


	return (count);
}

/**
 * print_number - prints an integer
 * @n: integer to print
 *
 * Return: number of character printed
*/
int print_number(int n)
{
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}
	else
	{
		num = n;
	}
	if (num / 10)
		count += print_number(num / 10);

	count += _putchar((num % 10) + '0');

	return (count);
}

/**
 * print_binary - prints an unsigned int in binary
 * @n: unsigned int number
 *
 * Return: number of characters printed
*/
int print_binary(unsigned int n)
{
	int count = 0;
	unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);
	int started = 0;

	if (n == 0)
		return (_putchar('0'));

	while (mask)
	{
		if (n & mask)
		{
			_putchar('1')
				count++;
			started = 1;
		}
		else if (started)
		{
			_putchar('0');
			count++;
		}
		mask >>= 1;
	}
	return (count);
}
