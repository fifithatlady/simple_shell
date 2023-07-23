#include "shell.h"

/**
 * _strcmp - a function that compares two strings
 * @name: the string to be compared
 * @variable: second variable to compare with
 * @length: name length
 * Return: it returns 1, if strings are same else 0
 */
int _strcmp(char *name, char *variable, unsigned int length)
{
	unsigned int var_length;
	unsigned int i;

	var_length = _strlen(variable);
	if (var_length != length)
		return (-1);

	i = 0;
	while (name[i] != '\0' && variable[i] != '\0')
	{
		if (name[i] != variable[i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * _strncmp - a function that compares two strings number
 * @name: one of the string to be compared
 * @variable: the second string variable to compare with
 * @length: length of the variable to compare
 * Return: it returns 1, if strings are same else 0
 */
int _strncmp(char *name, char *variable, unsigned int length)
{
	unsigned int i;

	i = 0;
	while (i < length)
	{
		if (name[i] != variable[i])
			return (-1);
		i++;
	}
	return (1);
}

/**
 * *_strcpy - a function that copies string from the source to the destination
 * @dest: the destination
 * @src: the source
 * Return: it returns the string destination
 */
char *_strcpy(char *dest, char *src)
{
	int i;
	int j = _strlen(src);

	for (i = 0; i <= j; i++)
		dest[i] = src[i];

	return (dest);
}
/**
 * _strlen - a function that  returns the length of a string
 * @s: string to get its length
 * Return: it returns the string length
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}
