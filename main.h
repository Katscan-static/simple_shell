#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;
int _getcommand(char **av);
int _putchar(char c);
void _puts(char *str);
int _execute(char **tkns, char **av);
void handle_args(char **token);
int _strcmp(char *str1, char *str2);
int check_command(char *token);
char *str_concat(char *s1, char *s2);
int token_num(char *str, char *delim);
char **assign_token(char **token, char *line);


#endif
