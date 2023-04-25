#include <stdio.h>

/**
 * token_num - gets number of tokens
 * @str: string to be tokenized
 * @delim: string of characters to tokenize
 *
 * Return: number of tokens or 0 if it fails
 */

int token_num(char *str, char *delim)
{
	int i = 0, k = 1, j;

	if (!str || !delim)
		return (0);

	while (str[i])
	{
		j = 0;
		while (delim[j])
		{
			if (str[i] == delim[j])
				k++;
			j++;
		}
		i++;
	}

	return (k);
}
