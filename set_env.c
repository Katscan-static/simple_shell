#include "main.h"

/**
 * set_env - sets env
 * @args: arguments
 *
 * Return: 1 on failure 0 on success
 */
int set_env(char **args)
{
	int result;

	char *message = "Error: Not enough args";

	if (!args[1] || !args[2])
	{
		write(2, message, strlen(message));
		return (1);
	}
	else
	{
		result = setenv(args[1], args[2], 1);
		if (result)
		{
			perror("setenv");
			return (1);
		}
	}

	return (0);
}
