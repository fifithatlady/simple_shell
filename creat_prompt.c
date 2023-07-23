#include "shell.h"

/**
 * prompt - a function that checks mode and prints if interactive mode
 * @fd: file number
 * @buf: buffer
**/
void prompt(int fd, struct stat buf)
{
	fstat(fd, &buf);

	if (S_ISCHR(buf.st_mode))
		_puts(PROMPT);
}

/**
 * _puts - a function that prints a string
 * @str: string
 * Return: it returns void
 */
void _puts(char *str)
{
	unsigned int length;

	length = _strlen(str);

	write(STDOUT_FILENO, str, length);
}
