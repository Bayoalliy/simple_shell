#include "header.h"

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
	char *line = NULL;
	size_t pid, len = 0;
	int status;
	char *argv[] = {NULL, NULL, NULL, NULL};
	char *itr;

	while (1)
	{
		write(STDIN_FILENO, "#cisfun$ ", 9);
		if (getline(&line, &len, stdin) < 0)
		{
			free(line);
			exit(0);
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
			/*if(!(**argv))
				exit(0);
			*/
			if (execve(argv[0], argv, environ) == -1)
			{
				perror(av[ac - 1]);
				exit(1);
			}

		}
		else
		{
			wait(&status);
		}
	}

	return (0);
}
