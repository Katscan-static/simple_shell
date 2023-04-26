#include "main.h"
#include <stdio.h>
#include <stdlib.h>



/**
 * con_str - concatinate str
 * @s1: string 1
 * @s2: string 2
 * @p: pointer from malloc
 * @c1: s1 count
 * @c2: s2 count
 * Return: pointer from malloc
 */

char *con_str(char *s1, char *s2, char *p, int c1, int c2);

/**
 * str_concat - concatenate two strings
 * @s1: first string
 * @s2: second string
 * Return: pointer to string, or NULL if fail
 */

char *str_concat(char *s1, char *s2)
{
	char *p;
	int c1 = 0, c2 = 0;
	char n[1] = {'\0'};

	if (!s1)
		s1 = n;
	if (!s2)
		s2 = n;

	while (s1[c1])
		c1++;

	while (s2[c2])
		c2++;

	p = malloc(sizeof(char) * (c1 + c2) + 1);

	if (!p)
		return (NULL);

	return (con_str(s1, s2, p, c1, c2));
}

/**
 * con_str - concatinate str
 * @s1: string 1
 * @s2: string 2
 * @p: pointer from malloc
 * @c1: s1 count
 * @c2: s2 count
 * Return: pointer from malloc
 */

char *con_str(char *s1, char *s2, char *p, int c1, int c2)
{
	int i = 0, j = 0;

	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}

	while (s2[j])
	{
		p[c1 + j] = s2[j];
		j++;
	}
	p[c1 + c2] = '\0';

	return (p);
}
