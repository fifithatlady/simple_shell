#include "shell.h"
/**
**builtin_execute - a function that executes all built in functions
**@tokens: the arguments being passed to thwle environment
**Return: it returns 1
**/
int builtin_execute(char **tokens)
{
	int status;
	unsigned int length;
	unsigned int num;
	unsigned int i;

	built_s builtin[] = {
		{"exit", shell_exit},
		{"env", shell_env},
		{NULL, NULL}
	};

	if (tokens[0] == NULL)
		return (1);

	length = _strlen(tokens[0]);

	num = shell_num_builtins(builtin);
	for (i = 0; i < num; i++)
	{
		if (_strcmp(tokens[0], builtin[i].name, length) == 0)
		{
			status = (builtin[i].p)();
			return (status);
		}
	}
	return (1);
}

/**
**shell_num_builtins - a function that check numbers of built-ins
**@builtin: the builtin variable  to be counted
**Return: it returns a value
**/

int shell_num_builtins(built_s builtin[])
{
	unsigned int i;

	i = 0;
	while (builtin[i].name != NULL)
		i++;

	return (i);
}
