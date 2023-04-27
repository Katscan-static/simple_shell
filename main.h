#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

void execute(char **args, char **av, char **path);
int handle_path(char **args, char **path);
char *str_concat(char *s1, char *s2);
void handle_args(char **args, char *line);
char *_strtok(char *str, const char *delimeter);
int _atoi(char *s);
int unset_env(char **args);
int _strlen(char *str);
int set_env(char **args);
int _strcmp(char *str1, char *str2);
void _puts(char *str);
int _putchar(char c);
void handle_interrupt(int signal);
void tokenize_line(char **args, char **line);
void is_interactive(char **av);
int *fetchline(int fd);
int *read_buffer(int fd);
char *cd_builtin(char *d_dir);
#endif
