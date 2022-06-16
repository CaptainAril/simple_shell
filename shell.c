#include "shell.h"
#include <stdio.h>

int main(void)
{
	char *cmd, **argv;
	int i, count;

	while (1)
	{
		prompt();

	 	cmd = _read();
		printf("cmd: %s\n", cmd);
		for (i=0; cmd[i]; i++)
			;
		printf("count: %i\n", i);
		count = word_count(cmd);
		printf("word count: %i\n", count);
		argv = parser(cmd, count);
		for (i = 0; i < count; i++)
			printf("argv[%i]: %s\n", i, argv[i]);

		if (fork() == 0)
		{
			if (execve(argv[0], argv, NULL) ==  -1)
				perror("Error");
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);

	free (argv);
	free(cmd);
}
