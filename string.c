#include "shell.h"

/**
 * _strlen - a function that return the string's length
 * @str: the string that has length that will be checked
 *
 * Return: the integer value of the string's length
 */
int _strlen(char *str)
{
	int a = 0;

	if (!str)
		return (0);

	while (*str++)
		a++;
	return (a);
}

/**
 * strcmp_func - a function that perform lexicogarphic
 * comparison of two strangs.
 * @s1: 1st string
 * @s2: 2nd string
 *
 * Return: if s1 < s2 then negative
 * positive if s1 > s2 ,if s1 == s2 then zero
 */
int strcmp_func(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - a function that check if
 * a needle starts with haystack or no
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack otherwise a NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - a function that concatenate two strings
 * @de: the destination buffer
 * @src: the source buffer
 *
 * Return: the pointer to destination buffer
 */
char *_strcat(char *de, char *src)
{
	char *re = de;

	while (*de)
		de++;
	while (*src)
		*de++ = *src++;
	*de = *src;
	return (re);
}
