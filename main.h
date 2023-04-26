#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

void execute(char **args, char **av);
void _puts(char *str);
int _putchar(char c);
void handle_interrupt(int signal);
void tokenize_line(char **args, char **line);
void is_interactive(char **av);
#endif
