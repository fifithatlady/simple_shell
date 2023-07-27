#include "shell.h"

/**
 * read_line - Read a line from stdin
 *
 * Return: The line read from stdin
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t chars_read;

	chars_read = getline(&line, &bufsize, stdin);

	if (chars_read == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		} else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}

	line[chars_read - 1] = '\0';

	return (line);
}
