#include "shell.h"

/**
 * is_cmd -this func  determines if a file is an executable command
 * @info: this the info the info struct identfi
 * @path: path to the file thats being b
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - tghis clones characters
 * @pathstr: it is the PATH s way tring
 * @start: b eggining of thge  index
 * @stop: stopping index
 *
 * Return: pointer to new buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int num = 0, k = 0;

	for (k = 0, num = start; num < stop; num++)
		if (pathstr[num] != ':')
			buf[k++] = pathstr[num];
	buf[k] = 0;
	return (buf);
}

/**
 * find_path - it lookssgot  this cmd in the PATH string
 * @info: it is  the info structure of 
 * @pathstr: PATH string
 * @cmd: that the  cmd to find
 *
 * Return: this returns ( full path of cmd if found or NULL)
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int num = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[num] || pathstr[num] == ':')
		{
			path = dup_chars(pathstr, curr_pos, num);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[num])
				break;
			curr_pos = num;
		}
		num++;
	}
	return (NULL);
}
