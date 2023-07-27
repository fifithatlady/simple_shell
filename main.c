#include "shell.h"

/**
 * main - Entry point of the simple shell
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("$ ");
		line = read_line();
		args = parse_line(line);
		handle_variables(args);

		status = handle_builtins(args);
		if (status == 2)
		{
			free(line);
			free_args(args);
			continue;
		}

		status = execute(args);

		free(line);
		free_args(args);
	} while (status);

	return (0);
}
