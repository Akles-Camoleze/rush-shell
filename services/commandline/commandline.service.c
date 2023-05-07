#include "commandline.service.h"


void get_command_line(char **_buffer) {
    *_buffer = malloc_command_line();
    fgets(*_buffer, ARG_MAX, stdin);
    *_buffer[strcspn(*_buffer, "\n")] = '\0';
    *_buffer = realloc_command_line(*_buffer);
}

bool check_command(char *_command) {
    int i = 0;
    while (_command[i] == ' ') i++;
    if (i == strlen(_command)) return false;
    return true;
}