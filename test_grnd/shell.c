#include "shell.h"
#include <stdio.h>

int main(void)
{
	char *cmd, **argv;
	int i, word_count;

	while (1)
	{
		prompt();

	 	cmd = _read();
		printf("cmd: %s\n", cmd);
		for (i=0; cmd[i]; i++)
			;
		printf("count: %i\n", i);
		word_count = word_count(cmd);
		printf("word count: %i\n", word_count);
		argv = parser(cmd);

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
}
