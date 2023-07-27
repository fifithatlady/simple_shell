#include "shell.h"

/**
 * handle_builtins - Handles built-in commands.
 * @args: Array of arguments.
 *
 * Return: 1 if the command is a built-in, 0 otherwise.
 */
int handle_builtins(char **args)
{
	if (args == NULL || args[0] == NULL)
		return (0);

	if (strcmp(args[0], "env") == 0)
	{
		shell_env();
		return (1);
	}
	else if (strcmp(args[0], "cd") == 0)
	{
		return (shell_cd(args));
	}

	return (0);
}
