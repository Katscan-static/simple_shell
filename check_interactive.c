#include "main.h"

/**
 * is_interactive - check if shell is interactive
 */
void is_interactive(void)
{
	char *line = NULL, *args[64];
	size_t len = 0;
	ssize_t read = 0;
	int interactive = isatty(STDIN_FILENO);

	signal(SIGINT, handle_interrupt);

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
			execute(args);
		}

	} while (interactive);
	free(line);
}
