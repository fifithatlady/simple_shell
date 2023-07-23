#include <stdio.h>
#include "shell.h"

int main(void)
{
	char *tokens[] = {"exit", NULL};
	int status = builtin_execute(tokens);

	if (status == 0)
	{
		printf("Exit command executed successfully.\n");
	}
	else
	{
		printf("Exit command failed.\n");
	}

	return (0);
}
