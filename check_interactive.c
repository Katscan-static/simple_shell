#include "main.h"

/**
 * is_interactive - check if shell is interactive
 * @av: argument variables
 */
void is_interactive(char **av)
{
	char *line = NULL, *args[64];
	size_t len = 0;
	ssize_t read = 0;
	int interactive = isatty(STDIN_FILENO);


	do {
		if (interactive)
		{
			_puts("($) ");
			fflush(stdout);
		}

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			_putchar('\n');
			break;
		}
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		if (line[0] != '\0')
		{
			tokenize_line(args, &line);
			if (!(_strcmp(args[0], "exit")) || !(_strcmp(args[0], "env")) ||
				!(_strcmp(args[0], "setenv")) || !(_strcmp(args[0], "unsetenv")))
				handle_args(args);
			else
				execute(args, av);
		}

	} while (interactive);
	free(line);
}
