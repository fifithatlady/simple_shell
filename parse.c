#include "shell.h"

/**
 * parse_line - Parse the line into arguments
 * @line: The line to be parsed
 *
 * Return: An array of arguments
 */
char **parse_line(char *line);
{
	int bufsize = 64;
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens
					{
					perror("realloc");
					exit(EXIT_FAILURE);
					}
					{	token = strtok(NULL, " \t\r\n\a");
					}
					tokens[position] = NULL;
					return (tokens);
}
