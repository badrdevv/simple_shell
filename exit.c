#include "shell.h"

/**
 * strncpy_func - a function that copy a string
 * @des: the destination string to be copied
 * @src: the source string
 * @v: the amount of character to be copied
 *
 * Return: the concatenated string
 */

char *strncpy_func(char *des, char *src, int v)
{
	int a, b;
	char *str = des;

	a = 0;

	while (src[a] != '\0' && a < v - 1)
	{
		des[a] = src[a];
		a++;
	}
	if (a < v)
	{
		b = a;
		while (b < v)
		{
			des[b] = '\0';
			b++;
		}
	}
	return (str);
}

/**
 * strncat_func - a function that concatenate two strings
 * @des: 1 st string
 * @src: 2nd string
 * @v: the amount of bytes to be max used
 *
 * Return: the concatenated string
 */

char *strncat_func(char *des, char *src, int v)
{
	int a, b;
	char *str = des;

	a = 0;
	b = 0;
	while (des[a] != '\0')
		a++;
	while (src[b] != '\0' && b < v)
	{
		des[a] = src[b];
		a++;
		b++;
	}
	if (b < v)
		des[a] = '\0';
	return (str);
}

/**
 * strchr_func - a function that locate a character in a string
 * @str: the string that will be parsed
 * @chr: the character looking for
 *
 * Return: (str) a pointer to the memory area str
 */
char *strchr_func(char *str, char chr)
{ do {
	if (*str == chr)
		return (str);
} while (*str++ != '\0');

	return (NULL);
}
