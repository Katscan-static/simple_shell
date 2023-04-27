#include "main.h"

/**
 * handle_path - handles path
 * @args: arguments
 * @path: path for command
 *
 * Return: 0 if error else return 1 or 2
 */
int handle_path(char **args, char **path)
{
	char buf[1024];

	if (!(access(args[0], X_OK)))
		return (1);
	else if (getcwd(buf, sizeof(buf)))
	{
		chdir("/bin/");
		if (!(access(args[0], X_OK)))
		{
			*path = str_concat("/bin/", args[0]);
			if (!path)
				return (0);
			args[0] = *path;
			chdir(buf);
			return (2);
		}

		chdir(buf);
	}
	return (0);
}
