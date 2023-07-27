#include "shell.h"

/**
 * free_args - Free the memory used for storing arguments.
 * @args: The arguments to free.
 *
 * Return: void
 */
void free_args(char **args)
{
	char **current_arg = args;

	while (*current_arg)
	{
		free(*current_arg);
		current_arg++;
	}
	free(args);
}
