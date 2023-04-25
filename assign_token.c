#include "main.h"

/**
 * assign_token - assigns token to pointer array
 * @token: memory allocated pointer array
 * @line: line to be tokenized
 *
 * Return: array of pointers
 */
char **assign_token(char **token, char *line)
{
	int i = 0;

	token[i] = strtok(line, " ");

	while (token[i])
	{
		i++;
		token[i] = strtok(NULL, " ");
	}

	return (token);

}
