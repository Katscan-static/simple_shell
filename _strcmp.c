#include "main.h"
/**
 * _strcmp - compares two strings
 * @s1: first string.
 * @s2: second string.
 * Return: 0 if s1 and s2 are equals,
 * another number if not.
 */
int _strcmp(char *str1, char *str2)
{
	int m = 0;
	int n = 0;

	while (n == 0)
	{
		if ((*(str1 + m) == '\0') && (*(str2 + m) == '\0'))
				break;
		n = *(str1 + m) - *(str1 + m);
		m++;
	}
	return (n);
}
