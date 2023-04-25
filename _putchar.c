#include "main.h"
#include <unistd.h>
/**
 *
 * _putchar - writes the character c to stdout
 * @c: the character to print
 * Return: 1 (Success)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _puts - prints a string
 * @str: input string
 * Return: no return
 */
void _puts(char *str)
{
	int count = 0;

	while (count >= 0)
	{
		if (str[count] == '\0')
		{
			_putchar('\n');
			break;
		}
		_putchar(str[count]);
		count++;
	}
}
