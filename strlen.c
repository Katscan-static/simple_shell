#include "main.h"

/**
 * _strlen - get string length
 * @str: string t get length of
 *
 * Return: length of string
 */
int _strlen(char *str)
{
	int i = 0;

	if (!str)
		return (0);

	while (str[i])
		i++;

	return (i);
}
