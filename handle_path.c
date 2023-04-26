#include "main.h"

/**
 * handle_path - handles path
 * @args: arguments
 *
 * Return: 0 if error else return 1 or 2
 */
int handle_path(char **args)
{
	char buf[1024];

	if (!(access(args[0], X_OK)))
		return (1);
	else if (getcwd(buf, sizeof(buf)))
	{
		chdir("/bin/");
		if (!(access(args[0], X_OK)))
		{
			args[0] = str_concat("/bin/", args[0]);
			chdir(buf);
			return (2);
		}

		chdir(buf);
	}
	return (0);
}
