#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

/**
 * cd_builtin - implements the cd command
 * @d_dir: destination directory
 * Return: 0
 */
int cd_builtin(char *d_dir)
{
	char *h_dir = getenv("HOME");
	char cwd[4096];
	char *err_msg = strerror(errno);

	if (d_dir == NULL)
	{
		d_dir = h_dir;
	}
	else if (strcmp(d_dir, "-") == 0)
	{
		d_dir = getenv("OLDPWD");
		printf("%s\n", d_dir);
	}
	if (chdir(d_dir) != 0)
	{
		fprintf(stderr, "cd: error: could not chdir to '%s'\n", d_dir);
		return (1);
	}
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		fprintf(stderr, "cd: error: could not get cwd: %s\n", err_msg);
		return (1);
	}
	setenv("OLDPWD", getenv("PWD"), 1);
	setenv("PWD", cwd, 1);
	return (0);
}
