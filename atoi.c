#include "main.h"
#include <stdio.h>

/**
 * _atoi - number in a string
 * @s: string to be checked
 * Return: value to be checked
 */
int _atoi(char *s)
{
	unsigned int val = 0;
	int is_neg = 0;
	int is_pos = 0;


	do {

		if (*s == '-')
		{
			is_neg++;

		}
		else if (*s == '+')
		{
			is_pos++;

		}

		else if (*s >= 48 && *s <= 57)
		{
			val = val * 10 + (*s - 48);
		}
		else if (val > 0)
		{
			break;
		}
	} while (*s++);

	if (is_neg > is_pos || (is_neg != is_pos && is_neg % 2 != 0))
	{
		return (val = ~val + 1);
	}
	else
	{
		return (val);
	}
}
