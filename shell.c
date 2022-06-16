#include "shell.h"
#include <stdio.h>

int main(void)
{
	char *cmd, **argv;
	int count, i;

	while (1)
	{
		prompt();

	 	cmd = _read();
		printf("cmd: %s\n", cmd);

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

		free(cmd);
		free(argv);
	}
	return (0);

}
