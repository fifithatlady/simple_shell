#include "shell.h"

/**
 * shell_loop - The main loop for the shell program.
 *
 * Return: Always 0 (Success)
 */
int shell_loop(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("#cisfun$ ");
		line = read_line();
		args = split_line(line);
		handle_variables(args);
		status = execute(args);

		free(line);
		free_args(args);
	} while (status);

	return (0);
}
