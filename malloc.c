#include "shell.h"

/**
 * free_all - a function that frees all malloced spaces
 * @tokens: tokens array
 * @path: it points to a path variable
 * @line: user input
 * @fullpath: the full path of the environment variable
 * @flag: it flags any path that was malloced
 * Return: void
 */
void free_all(char **tokens, char *path, char *line, char *fullpath, int flag)
{
	free(path);
	free(tokens);
	free(line);
	if (flag == 1)
		free(fullpath);
}

/**
 * free_dp - a function frees a double pointer
 * @array: a double pointer to be freed
 * @length: the length of the array
 * Return: void
 */
void free_dp(char **array, unsigned int length)
{
	unsigned int i;

	i = 0;
	while (i < length)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

