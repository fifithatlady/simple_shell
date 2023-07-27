#include "shell.h"

/**
 * handle_variables - Handle variable substitution in arguments.
 * @args: The arguments to process.
 *
 * Return: void
 */
void handle_variables(char **args)

{
	char **current_arg = args;

	while (*current_arg)

	{
		if (strcmp(*current_arg, "$$") == 0)

	{
		char pid_str[16];

		sprintf(pid_str, "%d", getpid());
		*current_arg = strdup(pid_str);
	}
		else if (strcmp(*current_arg, "$?") == 0)
		{
			current_arg++;
		}
		current_arg++;
	}
}
