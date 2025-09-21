#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - simple shell
 *
 * @ac: argument count.
 *
 * @av: argument vector.
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	extern char **environ;
	char *argv[] = {NULL, NULL, NULL, NULL};
	char *line = NULL;
	size_t pid, len = 0;
	char *itr;
	int status;

	while (1)
	{
		write(STDIN_FILENO, "#cisfun$ ", 9);
		if (getline(&line, &len, stdin) < 0)
		{
			return (1);
		}
		itr = line;

		while (*itr)
		{
			if (*itr == '\n')
				*itr = '\0';
			itr++;
		}
		argv[0] = line;

		pid = fork();
		if (pid == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
				perror(av[ac - 1]);
		}
		else
		{
			wait(&status);
		}
	}

	return (0);
}
