#include "shell.h"

/**
 * prompt - Displays the prompt message
 */

void prompt(void)
{
	write(1, "$ ", 2);
}

/**
 * _read - reads the terminal input
 * Return: returns the terminal input as string
 */
char *_read(void)
{
	ssize_t char_read;
	size_t len = 0;
	char *buf = NULL;

	char_read = getline(&buf, &len, stdin);
	if (char_read == -1)
	{
		write(1, "\n", 1);
		free(buf);
		exit(0);
	}
	buf[char_read - 1] = 0;

	return (buf);
}

/**
 * parser - parses the terminal string input into tokens,
 *          stored in a NULL terminated array
 * @str: points to string to be parsed
 * @count: number of words in str
 * Return: Returns pointer to a NULL terminated array of tokens
 */
char **parser(char *str, int count)
{
	char *token;
	char **arr = malloc((count + 1) * sizeof(char *));
	const char *delim = " \t";
	int i = 0;

	if (arr == NULL)
	{

		perror("Error");
		exit(0);
	}

	token = strtok(str, delim);
	arr[0] = token;
	while (token != NULL)
	{
		i++;
		token = strtok(NULL, delim);
		arr[i] = token;
	}
	arr[i] = NULL;
	return (arr);
}
