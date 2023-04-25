#include "main.h"

/**
 * _execute - executes the command
 * @tkns: tokens to be used for execution
 * @av: argument variables
 *
 * Return: -1 on failure and 1 on success
 */
int _execute(char **tkns, char **av)
{
	pid_t my_pid;

	my_pid = fork();

	if (my_pid == 0)
	{
		if (execve(tkns[0], tkns, environ) == -1)
			perror(av[0]);
		exit(1);
	}
	else if (my_pid > 0)
		wait(NULL);

	return (1);
}
