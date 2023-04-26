#include "main.h"

/**
 * handle_args - handles exit and print env
 * @token: token to be compared
 */

void handle_args(char **token)


{
	int i = 0;

	if (!(_strcmp(token[0], "exit")))
		exit(EXIT_SUCCESS);
	if (!(_strcmp(token[0], "env")))
	{
		for (; environ[i]; i++)
		{
			_puts(environ[i]);
			_putchar('\n');
		}
	}
}
