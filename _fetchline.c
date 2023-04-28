#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * not_line - checks for not line prints error
 * @line: string to be checked
 */
void not_line(char *line)
{
	if (!line)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}
}
/**
 * read_buffer - reads into data
 * @fd: file descriptor
 * Return: read_chars
 */
char *read_buffer(int fd)
{
	static char buffer[BUFFER_SIZE];
	static int read_chars;

	read_chars = 0;

	read_chars = read(fd, buffer, BUFFER_SIZE);
	if (read_chars < 0)
	{
		perror("read error");
		exit(EXIT_FAILURE);
	}
	return (strndup(buffer, read_chars));
}
/**
 * fetchline - reads an entire line
 * @fd: file descriptor
 * Return: the read line
 */
char *fetchline(int fd)
{
	static char *buffer;
	static int buffer_pos,  buffer_size;
	char *line = NULL, m;
	int line_pos = 0, line_size = BUFFER_SIZE;

	buffer = NULL;
	buffer_pos = 0;
	buffer_size = 0;
	while (1)
	{
		if (buffer_pos >= buffer_size)
		{
			free(buffer);
			buffer = read_buffer(fd);
			buffer_size = strlen(buffer);
			buffer_pos = 0;
		}
		m = buffer[buffer_pos++];
		if (m == '\n')
		{
			line[line_pos] = '\0';
			return (line);
		}
		line[line_pos++] = m;
		if (line_pos >= line_size)
		{
			line_size += BUFFER_SIZE;
			line = realloc(line, line_size);
			not_line(line);
		}
		if (!line)
		{
			line = malloc(line_size);
			not_line(line);
		}
	}
}

