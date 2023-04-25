#include "main.h"
#include <unistd.h>
/**
 * _putchar - writes the character c to stdout
 * @c: the character to print
 *
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
	int i = 0;

	for (; str[i]; i++)
		_putchar(str[i]);

}
