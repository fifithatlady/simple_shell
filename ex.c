#include "shell.h"

/**
 * execute - Execute a command with arguments
 * @args: An array of arguments
 *
 * Return: Always 1 (success)
 */
int execute(char **args)
{
	if (args[0] == NULL)
	{
		return (1);
	}

	pid_t pid = fork();

	if (pid == 0)

	{
		if (execvp(args[0], args) == -1)
		{
			perror("execvp");
		}
		exit(EXIT_FAILURE);
	} else if (pid < 0)

	{
		perror("fork");
	} else

	{
		wait(NULL);
	}

	return (1);
}

/**
 * free_args - Free the array of arguments
 * @args: An array of arguments
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

/**
 * handle_variables - Handle variable replacement
 * @args: An array of arguments
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
		} else if (strcmp(*current_arg, "$?") == 0)
		{
			*current_arg = "0";
		}
		current_arg++;
	}
}

/**
 * handle_builtins - Handle built-in commands
 * @args: An array of arguments
 *
 * Return: 0 if exit built-in is called, 2 if env or cd built-in is called,
 * otherwise 1.
 */
int handle_builtins(char **args)
{
	if (strcmp(args[0], "exit") == 0)

	{
		return (0);

	} else if (strcmp(args[0], "env") == 0)
	{
		char **env = environ;

		while (*env)

		{
			printf("%s\n", *env);
			env++;
		}
		return (2);

	} else if (strcmp(args[0], "cd") == 0)

	{
		if (args[1] == NULL)
		{
			chdir(getenv("HOME"));
		} else
		{
			if (chdir(args[1]) == --0)
			{
				perror("cd");
			}
		}
		return (2);
	}

	return (1);
}
