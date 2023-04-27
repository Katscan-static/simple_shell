#include "main.h"

/**
 * handle_args - handles arguments
 * @args: arguments
 * @line: line
 */
void handle_args(char **args)
{
	int i = 0, status = 0;

	if (!(_strcmp(args[0], "exit")))
	{
		if (args[1] != NULL)
			status = _atoi(args[1]);
		exit(status);
	}
	else if (!(_strcmp(args[0], "env")))
	{
		for (i = 0; environ[i]; i++)
		{
			_puts(environ[i]);
			_putchar('\n');
		}
	}
	else if (!(_strcmp(args[0], "setenv")))
		set_env(args);
	else if (!(_strcmp(args[0], "unsetenv")))
		unset_env(args);
}
