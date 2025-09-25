#include "header.h"


/**
 * split_line - splits input into command and arguments.
 *
 * @line: input line
 *
 * @arr: will store the splitted line.
 * Return: array of strings.
 */
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
