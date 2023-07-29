#include "shell.h"

/**
 * interactive -this checks if shell is interactive mode
 * @info: it is  struct address
 *
 * Return :alway retun 1 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - this func checks if character is a delimeter
 * @c: it is the  the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha -func to checks for alphabetic character
 *@c: always The character to input
 *Return: 1 if c is alphabetic,will retun 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - this wil converts a string to an integer
 *@s: it is a  the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int num, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (num = 0;  s[num] != '\0' && flag != 2; num++)
	{
		if (s[num] == '-')
			sign *= -1;

		if (s[num] >= '0' && s[num] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[num] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
