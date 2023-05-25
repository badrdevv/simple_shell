#include "shell.h"

/**
 * hsh - the main shell loop
 * @info: the parameter & return info struct
 * @av: the argument vector from main()
 *
 * Return: on success (0), on error (1), otherwise error code
 */
int hsh(info_t *info, char **av)
{
	ssize_t a = 0;
	int builtin_ret = 0;

	while (a != -1 && builtin_ret != -2)
	{
		clear_info(info);
		if (interactive_func(info))
			_puts("$ ");
		_putchar(BUF_FLUSH);
		a = get_input(info);
		if (a != -1)
		{
			set_info(info, av);
			builtin_ret = find_builtin(info);
			if (builtin_ret == -1)
				find_cmd(info);
		}
		else if (interactive_func(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive_func(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_ret);
}

/**
 * find_builtin - a function that find a builtin command
 * @info: the parameter & return info struct
 *
 * Return: if builtin is not there (-1)
 * if builtin executed successfully (0)
 * if builtin found but not successful (1)
 * if builtin signals exit(-2)
 */
int find_builtin(info_t *info)
{
	int a, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", myexit_func},
		{"env", myenv_func},
		{"help", myhelp_func},
		{"history", myhistory_func},
		{"setenv", mysetenv_func},
		{"unsetenv", unsetenv_func},
		{"cd", mycd_func},
		{"alias", myalias_func},
		{NULL, NULL}
	};

	for (a = 0; builtintbl[a].type; a++)
		if (strcmp_func(info->argv[0], builtintbl[a].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[a].func(info);
			break;
		}
	return (built_in_ret);
}

/**
 * find_cmd - a function that find a command in PATH
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void find_cmd(info_t *info)
{
	char *path = NULL;
	int a, b;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (a = 0, b = 0; info->arg[a]; a++)
		if (!is_delim_func(info->arg[a], " \t\n"))
			b++;
	if (!b)
		return;

	path = find_path(info, getenv_func(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive_func(info) || getenv_func(info, "PATH=")
			|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error_func(info, "not found\n");
		}
	}
}

/**
 * fork_cmd - a function that fork a an executable thread to run cmd
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void fork_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error_func(info, "Permission denied\n");
		}
	}
}
