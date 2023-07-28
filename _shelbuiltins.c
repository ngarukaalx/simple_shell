#include "main.h"
/**
* _handle_shell_inbuilt - the function name
* @line: parameter of type char *.
* @array: parameter of type char **.
* @argv:number of arguments
* @env:pointer to environment variable
* Return: int .
*/
int _handle_shell_inbuilt(char *line, char **array,
		char **argv, Environment *env)
{
	int isArg = 0, exit_status = 0, j;

	if (_str_cmp(array[0], "exit") == 0)
	{
		if (array[1] != NULL)
		{
			isArg = _handle_exit(array);
			if (isArg == 1)
			{
				_print_f("%s: %d: exit: Illegal number: %s\n", argv[0], 1, array[1]);
				free_array(array);
				free(line);
				free_my_environ(env);
				exit(2);
			}
			exit_status = _exi_stat_(array);
		}
		free_array(array);
		free(line);
		free_my_environ(env);
		exit(exit_status);
	}
	if (_str_cmp(array[0], "env") == 0)
	{
		print_environment(env);
		return (2);
	}
	if (_str_cmp(array[0], "setenv") == 0)
	{
		j = handle_set_env(array, env);
		return (j);
	}
	if (_str_cmp(array[0], "unsetenv") == 0)
	{
		j = handle_unset_env(array, env);
		return (j);
	}
	return (0);
}
/**
* _handle_exit - Free allocated memory and terminate the shell.
* @array: An array of command line arguments.
* Return: int
*/
int _handle_exit(char **array)
{
	if (digit_checker(array[1]) != 0)
	{
		return (1);
	}
	return (0);
}
/**
* _exi_stat_ - fetch exit int from input.
* @array: An array of command line arguments.
* Return: int
*/
int _exi_stat_(char **array)
{
	int i, exit_status = 0;

	i = 0;
	while (array[1][i] != '\0')
	{
		exit_status = (exit_status * 10) + (array[1][i] - '0');
		i++;
	}
	return (exit_status);
}

/**
* handle_unset_env - handler for unsetting an environment variable
* @array: An array of command line arguments.
* @env: environment copy
* Return: int
*/
int handle_unset_env(char **array, Environment *env)
{
	if (array[1] == NULL)
	{
		_print_f("unsetenv: usage: unsetenv VARIABLE\n");
		return (2);
	}
	my_unsetenv(array[1], env);
	return (2);
}
/**
* handle_set_env - handler for setting an environment variable
* @array: An array of command line arguments.
* @env: environment copy
* Return: int
*/
int handle_set_env(char **array, Environment *env)
{
	if (array[1] == NULL)
	{
		_print_f("unsetenv: usage: unsetenv VARIABLE\n");
		return (2);
	}
	my_setenv(array[1], array[2], env);
	return (2);
}
