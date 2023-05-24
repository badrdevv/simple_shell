#include "shell.h"

/**
 * _strcpy - a function that copy a string
 * @de: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *de, char *src)
{
	int a = 0;

	if (de == src || src == 0)
		return (de);
	while (src[a])
	{
		de[a] = src[a];
		a++;
	}
	de[a] = 0;
	return (de);
}

/**
 * _strdup - a function that duplicate a string
 * @str: the string to be duplicated
 *
 * Return: the pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int len = 0;
	char *re;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	re = malloc(sizeof(char) * (len + 1));
	if (!re)
		return (NULL);
	for (len++; len--;)
		re[len] = *--str;
	return (re);
}

/**
 * _puts - a function that print an input string
 * @str: the string to be printed
 *
 * Return: void
 */
void _puts(char *str)
{
	int b = 0;

	if (!str)
		return;
	while (str[b] != '\0')
	{
		_putchar(str[b]);
		b++;
	}
}

/**
 * _putchar - a function that write the character c to standard output
 * @chr: The character that will be printed
 *
 * Return: 1 on Success
 * in case of a error, -1 is returned
 * and errno is set appropriately.
 */
int _putchar(char chr)
{
	static int a;
	static char buf[WRITE_BUF_SIZE];

	if (chr == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(1, buf, a);
		a = 0;
	}
	if (chr != BUF_FLUSH)
		buf[a++] = chr;
	return (1);
}
