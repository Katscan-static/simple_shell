#include "main.h"

/**
 * unset_env - unsets env
 * @args: arguments
 *
 * Return: 1 on failure 0 on success
 */
int unset_env(char **args)
{
	char *message = "Usage: unsetenv VARIABLE\n";
	int result;

	if (!args[1])
	{
		if (!args[1])
			write(2, message, strlen(message));
		return (1);
	}
	else
	{
		result = unsetenv(args[1]);
		if (!result)
			perror("unsetenv");
		return (1);
	}

	return (0);
}
