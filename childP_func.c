#include "shell.h"

/**
 * child - a child process function
 * @fullpath: the full path to the  executable variable
 * @tokens: it tokenized user input from the fullpath
 * Return: it rerurns 0
 */
int child(char *fullpath, char **tokens)
{
	pid_t child_pid;
	int status;
	int execve_status;
	char **envp = environ;

	child_pid = fork();
	if (child_pid == -1)
	{
		errors(1);
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		execve_status = execve(fullpath, tokens, envp);
		if (execve_status == -1)
			return (-1);
	}
	else
		wait(&status);

	return (0);
}
