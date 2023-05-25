#include "shell.h"

/**
 * _erratoi - a function tha convert a string to an integer
 * @str: the string that will be converted
 *
 * Return: if no numbers in string then 0, otherwhise converted number
 * in casee of error: -1
 */

int _erratoi(char *str)
{
	int a = 0;
	unsigned long int res = 0;

	if (*str == '+')
		str++;
	for (a = 0; str[a] != '\0'; a++)
{
		if (str[a] >= '0' && str[a] <= '9')
		{
			res *= 10;
			res += (str[a] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}

/**
 * print_error_func - a function that print an error message
 * @info: the parameter & return info struct
 * @errstr: the string that contains a specified error type
 * Return: if no numbers in string then 0, otherwise converted number
 * in case of error: -1
 */
void print_error_func(info_t *info, char *errstr)
{
	_puts(info->fname);
	_puts(": ");
	print_d(info->line_count, STDERR_FILENO);
	_puts(": ");
	_puts(info->argv[0]);
	_puts(": ");
	_puts(errstr);
}

/**
 * print_d - a function that print a decimal integer number
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters that will be printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int a, co = 0;
	unsigned int abs, current;

	if (fd == STDERR_FILENO)
		__putchar = _putchar;
	if (input < 0)
	{
		abs = -input;
		__putchar('-');
		co++;
	}
	else
		abs = input;
	current = abs;
	for (a = 1000000000; a > 1; a /= 10)
	{
		if (abs / a)
		{
			__putchar('0' + current / a);
			co++;
		}
		current %= a;
	}
	__putchar('0' + current);
	co++;

	return (co);
}

/**
 * convert_number - a function that convert a clone of itoa
 * @num: the number
 * @base: the base
 * @flags: the argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - a function that replace the
 * first instance of '#' with '\0'
 * @buf: the address of the string that will be modified
 *
 * Return: Always 0 (Success)
 */
void remove_comments(char *buf)
{
	int a;

	for (a = 0; buf[a] != '\0'; a++)
		if (buf[a] == '#' && (!a || buf[a - 1] == ' '))
		{
			buf[a] = '\0';
			break;
		}
}
