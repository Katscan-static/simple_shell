#include "main.h"

/**
 * new_env - make new environ
 * @i: index
 * @name: name
 * @temp: temporary
 * @value: value
 *
 * Return: 0 on success 1 on failure
 */
int new_env(int i, char *name, char *temp, char *value)
{
	char **new_environ;

	new_environ = malloc((i + 2) * sizeof(char *));
	if (!new_environ)
		return (1);
	for (i = 0; environ[i]; i++)
		new_environ[i] = environ[i];
	new_environ[i] = malloc(_strlen(name) + _strlen(value) + 2);
	if (!new_environ[i])
		return (1);
	temp = str_concat(name, "=");
	new_environ[i] = str_concat(temp, value);
	free(temp);
	new_environ[i + 1] = NULL;
	environ = new_environ;

	return (0);
}

/**
 * set_env - sets env
 * @args: arguments
 *
 * Return: 1 on failure 0 on success
 */
int set_env(char **args)
{
	char *message = "Error: Not enough args";
	char *name, *value, *temp;
	int i, fnd;

	if (!args[1] || !args[2])
	{
		write(2, message, _strlen(message));
		return (1);
	}
	name = args[1];
	value = args[2];

	for (i = 0; environ[i]; i++)
	{
		temp = _strtok(environ[i], "=");
		if (_strcmp(temp, name))
		{
			fnd = 1;
			break;
		}
	}

	if (fnd)
	{
		environ[i] = malloc(_strlen(name) + _strlen(value) + 2);
		if (!environ[i])
			return (1);
		temp = str_concat(name, "=");
		environ[i] = str_concat(temp, value);
		free(temp);
	}
	else
		new_env(i, name, temp, value);

	return (0);
}
