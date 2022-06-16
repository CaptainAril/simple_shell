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
 * parser - parses the terminal string input into tokens,
 *          stored in a NULL terminated array
 * @buf - points to string to be parsed
 * Return: Returns pointer to a NULL terminated array of tokens
 */
char **parser(char *str, int count)
{
	char *token;
	char **arr = malloc(sizeof(char *)  * (count + 1));
	const char *delim = " ";
	int i;

	if( arr == NULL)
	{
		perror("Error");
		exit (0);
	}

	token = strtok(str, delim);
	arr[0] = token;
	i = 1;
	while (token != NULL)
	{
		token = strtok(NULL, delim);
		arr[i] = token;
		i++;
	}
	arr[i] = NULL;
	return(arr);
}
