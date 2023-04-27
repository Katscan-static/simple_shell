#include "main.h"

/**
 * tokenize_line - tokenize line
 * @args: arguments
 * @line: string to tokenize
 */
void tokenize_line(char **args, char **line)
{
	char *tkn = NULL;
	int i = 0;

	for (tkn = _strtok(*line, " "); tkn; tkn = _strtok(NULL, " "), i++)
		args[i] = tkn;
	args[i] = NULL;
}
