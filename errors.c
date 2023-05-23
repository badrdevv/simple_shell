#include "shell.h"

/**
 * puts_func - a function  that print an input string
 * @s: the string to be printed
 *
 * Return: void
 */

void puts_func(char *s)
{
	int a = 0;

	if (!s)
		return;
	while (s[a] != '\0')
	{
		putchar_func(s[a]);
		a++;
	}
}

/**
 * putchar_func - a function that write the character c
 * to standar error
 * @chr: the character to be printed
 *
 * Return: 1 if everything is alright
 * -1 is returned if there is an error, and errno is set appropriately.
 */

int putchar_func(char chr)
{
	static int a;
	static char buf[WRITE_BUF_SIZE];

	if (chr == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(2, buf, a);
		a = 0;
	}

	if (chr != BUF_FLUSH)
		buf[a++] = chr;
	return (1);
}

/**
 * putfd_func - function that write the character c to given fd
 * @chr: the character to be printed
 * @fld: the filedescriptor to write to
 *
 * Return: 1 if sucess
 * -1 is returned if there is an error and errno is set appropriately.
 */

int putfd_func(char chr, int fld)
{
	static int a;
	static char buf[WRITE_BUF_SIZE];

	if (chr == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(fld, buf, a);
		a = 0;
	}
	if (chr != BUF_FLUSH)
		buf[a++] = chr;
	return (1);
}

/**
 * putsfd_func - a function that print an intput string
 * @s: the string to be printed
 * @fld: the filedescriptor to write to
 *
 * Return: the number of charputs
 */

int putsfd_func(char *s, int fld)
{
	int a = 0;

	if (!s)
		return (0);
	while (*s)
	{
		a += putfd_func(*s++, fld);
	}
	return (a);
}
