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
int handle_path(char **args);
char *str_concat(char *s1, char *s2);
void handle_args(char **args);
int _strcmp(char *str1, char *str2);
void _puts(char *str);
int _putchar(char c);
void handle_interrupt(int signal);
void tokenize_line(char **args, char **line);
void is_interactive(char **av);
int *fetchline(int fd);
int *read_buffer(int fd);
#endif
