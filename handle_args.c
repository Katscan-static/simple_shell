#include "main.h"

/**
 * handle_args - handles arguments
 * @args: arguments
 * @line: line
 */
void handle_args(char **args)
{
	int i = 0;

	if (!(_strcmp(args[0], "exit")))
	{
		for (i = 0; args[i]; i++)
			free(args[i]);
		exit(1);
	}
	else if (!(_strcmp(args[0], "env")))
	{
		for (i = 0; environ[i]; i++)
		{
			_puts(environ[i]);
			_putchar('\n');
		}
	}
}
