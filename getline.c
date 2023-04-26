#include "main.h"

/**
 * _getcommand - gets command and executes
 * @av: argument variable
 *
 * Return: 1 on success 0 on failure
 */
int _getcommand(char **av)
{
	char *line = NULL, **token = NULL;
	size_t len = 0;
	ssize_t read;
	int tkn_num;
	int interactive = isatty(STDIN_FILENO);

	do {
		if (interactive)
		_puts("($) ");
		read = getline(&line, &len, stdin);
		if (read != -1)
		{
			if (line[read - 1] == '\n')
				line[read - 1] = '\0';
		}
		if (read == EOF)
		{
			_putchar('\n');
			break;
		}
		tkn_num = token_num(line, " ");
		if (tkn_num)
			token = malloc(sizeof(char *) * (tkn_num + 1));
		if (!token)
		{
			free(line);
			return (0);
		}
		token = assign_token(token, line);
		handle_args(token);
		if (!(_strcmp(token[0], "exit")) && !(strcmp(token[0], "env")))
			_execute(token, av);
		free(token);
		token = NULL;
	} while (interactive);
	free(line);
	if (token)
		free(token);
	return (1);
}
