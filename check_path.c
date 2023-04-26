#include "main.h"

/**
 * check_command - if command exists
 * @token: command to be checked
 *
 * Return: 1 or 2 if executable else 0
 */
int check_command(char *token)
{
	int cm_ex, ch_st;
	char cwd[1024];

	cm_ex = access(token, X_OK);
	if (!cm_ex)
		return (1);

	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return (0);
	ch_st = chdir("/bin/");
	if (!ch_st)
	{
		cm_ex = access(token, X_OK);
		if (!cm_ex)
		{
			if (!chdir(cwd))
				return (2);
		}
	}


	return (0);

}
