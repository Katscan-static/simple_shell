#include "main.h"
/**
 * _strcmp - compares two strings
 * @str1: first string.
 * @str2: second string.
 *
 * Return: 0 if str1 and str2 are equals,
 */
int _strcmp(char *str1, char *str2)
{
	int m = 0;
	int n = 0;

	while (n == 0)
	{
		if ((str1[m] == '\0') && (str2[m] == '\0'))
			break;
		n = str1[m] - str2[m];
		m++;
	}
	return (n);
}
