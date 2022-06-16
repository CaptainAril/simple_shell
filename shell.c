#include "shell.h"
#include <stdio.h>

int main(void)
{
	char *cmd, **argv;
	int count;

	while (1)
	{
		prompt();

	 	cmd = _read();
		count = word_count(cmd);
		argv = parser(cmd, count);

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
