#include "shell.h"

/**
 * myenv_func - a function that print the current environment
 * @info: a normal structure that contains some arguements.
 * it used to maintain some constant function prototype.
 *
 * Return: Always 0 (Success)
 */

int myenv_func(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * getenv_func - a function that get the value of an environ variable
 * @info: a normal structure that contains some arguements.
 * used to maintain
 * @na: env var name
 *
 * Return: value
 */

char *getenv_func(info_t *info, const char *na)
{
	list_t *node = info->env;
	char *q;

	while (node)
	{
		q = starts_with(node->str, na);

		if (q && *q)
			return (q);
		node = node->next;
	}
	return (NULL);
}

/**
 * mysetenv_func - a function that initialize a new environment variable,
 * or maby modify an existing one
 * @info: a normal structure that contains some arguements.
 * used to maintain a const function prototype.
 *
 * Return: Always 0 (Sucess)
 */

int mysetenv_func(info_t *info)
{
	if (info->argc != 3)
	{
		puts_func("incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * unsetenv_func - a function that removes an environment variable
 * @info: a normal structure that contains some arguements
 * used to maintain a const function prototype.
 *
 * Return: Always 0 (Sucess)
 */

int unsetenv_func(info_t *info)
{
	int a;

	if (info->argc == 1)
	{
		puts_func("too few arguements.\n");
		return (1);
	}
	for (a = 1; a <= info->argc; a++)
		_unsetenv(info, info->argv[a]);
	return (0);
}

/**
 * populate_env_list_func - a function that populate env linked list
 * @info: a normal structure that contains some arguements.
 * used to maintain a const function prototype.
 *
 * Return: Always 0 (Success)
 */

int populate_env_list_func(info_t *info)
{
	list_t *node = NULL;
	size_t a;

	for (a = 0; environ[a]; a++)
		add_node_end(&node, environ[a], 0);
	info->env = node;
	return (0);
}
