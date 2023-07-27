#include <string.h>
#include "shell.h"

/**
 * handle_builtins - Handle built-in commands.
 * @args: The arguments to process.
 *
 * Return: 0 if the shell should exit, 2 for 'env' and 'cd', 1 otherwise.
 */
int handle_builtins(char **args)
{
	if (strcmp(args[0], "exit") == 0)

		return (0);

}
else if (strcmp(args[0], "env") == 0)
{
	char **env = environ;

	while (*env)

	{
		printf("%s\n", *env);
		env++;
	}

	return (2);

}
else if (strcmp(args[0], "cd") == 0)
{
	if (args[1] == NULL)
	{
		chdir(getenv("HOME"))

	}
	else
	{
		if (chdir(args[1]) == -1)
		{
			perror("cd");
		}
	}
	return (2);
}

return (1);
}
