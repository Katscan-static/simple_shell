#include "main.h"

/**
 * execute - execute command
 * @args: arguments
 */
void execute(char **args)
{
	pid_t my_pid;
	int status;

	my_pid = fork();

	if (my_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (my_pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("exec");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(my_pid, &status, 0) == -1)
			perror("waitpid");
	}
}
