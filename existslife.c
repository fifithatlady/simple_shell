#include "shell.h"

/**
 **_strncpy - s clones or copies a string in the bfunc
 *@dest: it is tthe destina string to be copied to othe files fo excecu
 *@src: e source stringin th fil
 *@n: stands for amount of characters to be copied
 *Return:  concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int num, j;
	char *s = dest;

	num = 0;
	while (src[num] != '\0' && num < n - 1)
	{
		dest[num] = src[num];
		num++;
	}
	if (num < n)
	{
		j = num;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - this func  will concatenates two strings
 *@dest: it is tghe  first string
 *@src: this one is the b /2nd string
 *@n: represents quantity of bytes to be maximally used
 *Return: always return the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int num, j;
	char *s = dest;

	num = 0;
	j = 0;
	while (dest[num] != '\0')
		num++;
	while (src[j] != '\0' && j < n)
	{
		dest[num] = src[j];
		num++;
		j++;
	}
	if (j < n)
		dest[num] = '\0';
	return (s);
}

/**
 **_strchr - this locates locates a character in a string
 *@s: it is the string to be parsed
 *@c:  character to look for
 *Return: this (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
