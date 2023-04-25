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
int token_num(char *str, char *delim);
char **assign_token(char **token, char *line);


#endif
