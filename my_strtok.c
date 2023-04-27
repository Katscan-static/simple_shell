#include "main.h"

/**
 * con_del - checks consecutive delimeters
 * @next_token: token to be checked
 * @delimeter: delimeters
 *
 * Return: 1 always successful
 */
int con_del(char **next_token, const char *delimeter)
{
	int check = 0, i;

	while (**next_token)
	{
		check = 0;
		for (i = 0; delimeter[i] && **next_token; i++)
		{
			if (**next_token == delimeter[i])
			{
				**next_token = '\0';
				(*next_token)++;
				check = 1;
			}
		}
		if (!check)
			return (1);
	}
	return (1);
}

/**
 * _strtok - custom strtok
 * @str: string to be tokenized
 * @delimeter: delimeters
 *
 * Return: pointer to new token
 */
char *_strtok(char *str, const char *delimeter)
{
	static char *next_token;
	char *start_token;
	int fnd_del, i;

	if (str)
		next_token = str;
	else if (!next_token || !(*next_token))
		return (NULL);
	con_del(&next_token, delimeter);
	start_token = next_token;
	fnd_del = 0;
	while (*next_token)
	{
		for (i = 0; delimeter[i]; i++)
		{
			if (*next_token == delimeter[i])
			{
				*next_token = '\0';
				next_token++;
				con_del(&next_token, delimeter);
				fnd_del = 1;
				break;
			}
		}

		if (fnd_del)
			break;
		next_token++;
	}

	if (!start_token || !next_token)
		return (NULL);
	return (start_token);
}
