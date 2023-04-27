#include "main.h"

/**
 * execute - execute command
 * @args: arguments
 * @av: argument variable
 * @path: path for command
 */
void execute(char **args, char **av, char **path)
{
	pid_t my_pid = -1;
	int status = 0, p_stat;

	p_stat = handle_path(args, path);
	if (p_stat == 0)
	{
		_puts(av[0]);
		_puts(": ");
		_puts(args[0]);
		_puts(": command not found\n");
		return;
	}
	else
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
		{
			perror(av[0]);
		}
	}
}
