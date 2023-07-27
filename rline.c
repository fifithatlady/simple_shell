#include "shell.h"

/**
 * read_line - Read a line of input from the user.
 *
 * Return: The pointer to the input line.
 */
char *read_line(void)
{
	char *line = NULL;
	ssize_t bufsize = 0;

	getline(&line, &bufsize, stdin);

	return (line);

}
