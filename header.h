#ifndef __SHELL__
#define __SHELL__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char** split_line(char *line);

#endif
