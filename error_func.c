#include "shell.h"

/**
 * errors - a function prints case errors based
 * @error: error numbers to be printed
 * Return: it returns void
 */
void errors(int error)
{
	switch (error)
	{
	case 1:
		write(STDERR_FILENO, ERR_FORK, _strlen(ERR_FORK));
		perror("Error");
		break;

	case 2:
		perror("Error");
		break;

	case 3:
		write(STDERR_FILENO, ERR_MALLOC, _strlen(ERR_MALLOC));
		break;
	case 4:
		write(STDERR_FILENO, ERR_PATH, _strlen(ERR_PATH));
		break;

	default:
		return;
	}
}
