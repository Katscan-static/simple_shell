#include "main.h"

/**
 * main - entry point
 * @ac: argument count
 * @av: argument variables
 *
 * Return: always 0
 */
int main(int ac, char **av)
{
	int i = ac;

	is_interactive(av);
	i = 0;

	return (i);
}
