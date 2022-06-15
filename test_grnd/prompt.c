#include "shell.h"

/**
 * prompt - Displays the prompt message
 */
void prompt(void)
{
	write (1, "$ ", 2);
}

char *_read(void)
{
	ssize_t char_read;
	size_t len = 0;
	char *buf = NULL, *str;

	if((char_read = getline(&buf, &len, stdin)) == -1)
	{
		free(buf);
		exit(0);
	}
	buf[char_read - 1] = 0;
	str = buf;
	printf("read: %s\n", buf);
	printf("str1: %s\n", str);

	printf("str: %s\n", str);
	return (str);
}

/**
 * parser - parses the twerminal input into tokens,
 *          stored in a NULL terminated array
 * @buf - points to string to be parsed
 * Return: Returns pointer to a NULL terminated array of tokens
 */
char **parser(char *str)
{
	char *token;
	const char *delim = " ";
	int i;

	token = strtok(str, delim);
	printf("parser str: %s\n", str);
	printf("token 1: %s\n", token);
	printf("parser str: %s\n", str);
	i = 1;
	while (token != NULL)
	{
		token[i] = strtok(NULL, delim);
		i++;
		printf("%s->", token[i]);
	}
	token[i] = NULL;
	printf("%s\n", token);
	return(token);
}
