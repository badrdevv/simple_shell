#include "shell.h"

/**
 * interactive_func - a function that return true if
 * shell is interactive mode
 * @info: the structure address
 *
 * Return: if interactive mode then 1, otherwise 0
 */
int interactive_func(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim_func - a function that check if character is a delimeter
 * @chr: the character that will be checked
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim_func(char chr, char *delim)
{
	while (*delim)
		if (*delim++ == chr)
			return (1);
	return (0);
}

/**
 * isalpha_func - a function that check for alphabetic character
 * @chr: input by the user (character)
 * Return: if c is alphabetic then 1, Otherwise 0
 */

int isalpha_func(int chr)
{
	if ((chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * atoi_func - converts a string to an integer
 * @str: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int atoi_func(char *str)
{
	int a, si = 1, fl = 0, output;
	unsigned int re = 0;

	for (a = 0;  str[a] != '\0' && fl != 2; a++)
	{
		if (str[a] == '-')
			si *= -1;

		if (str[a] >= '0' && str[a] <= '9')
		{
			fl = 1;
			re *= 10;
			re += (str[a] - '0');
		}
		else if (fl == 1)
			fl = 2;
	}

	if (si == -1)
		output = -re;
	else
		output = re;

	return (output);
}
