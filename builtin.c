#include "shell.h"

/**
 * myexit_func - a function that exit the shell
 * @info: a Structure contains some arguments. it is used to maintain
 * a function prototype.
 * Return: exits with exit status
 * if info.argv[0] != "exit" then it is 0
 */
int myexit_func(info_t *info)
{
	int exitcheck;

	if (info->argv[1])  /* If there is an exit arguement */
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error_func(info, "Illegal number: ");
			puts_func(info->argv[1]);
			putchar_func('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * mycd_func - a function that change the current directory of the process
 * @info: a Structure that contains some arguments. it is used to maintain
 * some function prototype.
 * Return: Always 0 (Success)
 */
int mycd_func(info_t *info)
{
	char *str, *dire, buffer[1024];
	int chdir_ret;

	str = getcwd(buffer, 1024);
	if (!str)
		puts_func("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dire = getenv_func(info, "HOME=");
		if (!dire)
			chdir_ret = /* TODO: what should this be? */
				chdir((dire = getenv_func(info, "PWD=")) ? dire : "/");
		else
			chdir_ret = chdir(dire);
	}
	else if (strcmp_func(info->argv[1], "-") == 0)
	{
		if (!getenv_func(info, "OLDPWD="))
		{
			puts_func(str);
			_putchar('\n');
			return (1);
		}
		puts_func(getenv_func(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dire = getenv_func(info, "OLDPWD=")) ? dire : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error_func(info, "can't cd to ");
		puts_func(info->argv[1]), _putchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", getenv_func(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * myhelp_func - a function that change the current directory of the process
 * @info: a Structure that contains some arguments.
 * that will be used to maintain
 * somefunction prototype.
 * Return: Always 0 (Success)
 */
int myhelp_func(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	puts_func("help call works. Function not yet implemented \n");
	if (0)
		puts_func(*arg_array); /* temp att_unused workaround */
	return (0);
}
