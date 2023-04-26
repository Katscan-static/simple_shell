#include "main.h"

/**
 * execute - execute command
 * @args: arguments
 * @av: argument variable
 */
void execute(char **args, char **av)
{
	pid_t my_pid;
	int status;

	if (handle_path(args))
		my_pid = fork();

	if (my_pid == -1)
	{
		perror(av[0]);
		exit(EXIT_FAILURE);
	}
	else if (my_pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror(av[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(my_pid, &status, 0) == -1)
			perror(av[0]);
	}
}
