#include "header.h"


char** split_line(char *line)
{
    char *word;
    char **arr;
    char *itr = line;
    int n = 1;

   /*remove line break from line.*/
    while (*itr)
    {
        if (*itr == '\n')
            *itr = '\0';
        itr++;
    }

    word = strtok(line, " ");
    if(!word)
    {
        return(NULL);
    }

    arr = malloc(sizeof(char *) * 4);
    *arr = word;
    while((word = strtok(NULL, " ")))
    {
        /*arr = realloc(arr, sizeof(char *) * (n + 2));*/
        *(arr + n) = word;
        n++;
    }
    *(arr + n) = NULL;

    return(arr);
}

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
	char **argv;

	while (1)
	{
		write(STDIN_FILENO, "#cisfun$ ", 9);
		if (getline(&line, &len, stdin) < 0)
		{
			free(line);
			exit(0);
		}

		argv = split_line(line);
		pid = fork();
		if (pid == 0)
		{
			if(!(**argv))
				exit(0);
			
			if (execve(argv[0], argv, environ) == -1)
			{
				free(argv);
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
