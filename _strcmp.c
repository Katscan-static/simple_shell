#include "main.h"
/**
 * _strcmp - compares two strings
 * @str1: first string.
 * @str2: second string.
 * Return: 0 if str1 and str2 are equals,
 * another number if not.
 */

int _strcmp(char *str1, char *str2)
{
	int m = 0, op = 0;

	while (op == 0)
	{
		if ((*(str1 + m) == '\0') && (*(str2 + m) == '\0'))
			break;
		op = *(str1 + m) - *(str2 + m);
		m++;
	}

	return (op);
}
