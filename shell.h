#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

void prompt(void);
char *_read(void);
char **parser(char *str, int count);

/* string handlers */
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int word_count(char *str);

#endif
