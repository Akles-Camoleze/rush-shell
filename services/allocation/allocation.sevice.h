#ifndef RUSH_SHELL_ALLOCATION_SEVICE_H

#define RUSH_SHELL_ALLOCATION_SEVICE_H

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <linux/limits.h>

char *malloc_command_line();
char *realloc_command_line(char **_command);

#endif //RUSH_SHELL_ALLOCATION_SEVICE_H
