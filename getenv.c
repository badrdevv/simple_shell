#include "shell.h"

/**
 * get_environ - a function that return a string array copy of our environ
 * @info: a structure that contains some arguments.
 * it is used to maintain some function prototypes
 *
 * Return: Always 0 (Success)
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - a function that remove an environment variable
 * @info: a structure that contains some arguments
 * it is used to maintain some function prototypes
 *
 * Return: delete then 1, otherwise 0
 * @var: the string env var property
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t a = 0;
	char *q;

	if (!node || !var)
		return (0);

	while (node)
	{
		q = starts_with(node->str, var);
		if (q && *q == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), a);
			a = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		a++;
	}
	return (info->env_changed);
}

/**
 * _setenv - a function that initialize a new environment variable
 * otherwise modify an existing one
 * @info: a structure that contains some arguments.
 * it is used to main some function prototypes
 * @var: the string env var property
 * @value: the string env var value
 * Return: Always 0 (Success)
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *bu = NULL;
	list_t *node;
	char *q;

	if (!var || !value)
		return (0);

	bu = malloc(_strlen(var) + _strlen(value) + 2);
	if (!bu)
		return (1);
	_strcpy(bu, var);
	_strcat(bu, "=");
	_strcat(bu, value);
	node = info->env;
	while (node)
	{
		q = starts_with(node->str, var);
		if (q && *q == '=')
		{
			free(node->str);
			node->str = bu;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), bu, 0);
	free(bu);
	info->env_changed = 1;
	return (0);
}
