#include "shell.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * handle_redirection - Handle input/output redirection.
 * @args: The arguments to process.
 * @is_input_redirection: 1 if input redirection is present, 0 otherwise.
 * @is_output_redirection: 1 if output redirection is present, 0 otherwise.
 *
 * Return: void
 */
void handle_redirection(char **args, int is_input_redirection, int is_output_redirection)

{
	if (is_input_redirection)
	{
		int fd = open(args[0], O_RDONLY);

		if (fd == -1)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}
		if (dup2(fd, STDIN_FILENO) == -1)
		{
			perror("dup2");
			close(fd);
			exit(EXIT_FAILURE);
		}
		close(fd);
	}
	if (is_output_redirection)
	{
		int fd = open(args[1], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

		if (fd == -1);
		{
			perror("open");
			exit(EXIT_FAILURE);
		}
		if (dup2(fd, STDOUT_FILENO) == -1)
		{
			perror("dup2");
			close(fd);
			exit(EXIT_FAILURE);
		}

		close(fd);

	}
}
