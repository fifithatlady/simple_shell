#include "shell.h"

/**
 * shell_env - Display environment variables.
 *
 * Return: Always 0.
 */
int shell_env(void)
{
	/* Declare variables at the beginning of the block */
	char **env_var = environ;

	printf("Environment variables:\n");
	while (*env_var != NULL)
	{
		printf("%s\n", *env_var);
		env_var++;
	}
	return (0);
}

/**
 * shell_exit - Exit the shell.
 *
 * Return: Always 0.
 */
int shell_exit(void)
{
	printf("Exiting the shell.\n");
	return (0);
}

/**
 * builtin_execute - Execute built-in functions.
 * @tokens: The arguments being passed to the environment.
 *
 * Return: Always 1.
 */
int builtin_execute(char **tokens)
{
	int status;
	unsigned int length;
	unsigned int num;
	unsigned int i;

	built_s builtin[] = {
		{"exit", shell_exit},
		{"env", shell_env},
		{NULL, NULL}
	};

	if (tokens[0] == NULL)
		return (1);

	length = _strlen(tokens[0]);

	num = shell_num_builtins(builtin);
	for (i = 0; i < num; i++)
	{
		if (_strcmp(tokens[0], builtin[i].name, length) == 0)
		{
			status = (builtin[i].p)();
			return (status);
		}
	}
	return (1);
}

/**
 * shell_num_builtins - Count the number of built-in functions.
 * @builtin: The builtin variable to be counted.
 *
 * Return: The number of built-in functions.
 */
int shell_num_builtins(built_s builtin[])
{
	unsigned int i;

	i = 0;
	while (builtin[i].name != NULL)
		i++;

	return (i);
}
