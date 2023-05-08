#include "commandline.service.h"

void get_command_line(char **_buffer) {
    *_buffer = malloc_command_line();
    fgets(*_buffer, ARG_MAX, stdin);
    (*_buffer)[strcspn(*_buffer, "\n")] = 0;
    *_buffer = realloc_command_line(*_buffer);
}

bool check_command(char *_command) {
    check_exit(_command);
    int i = 0;
    while (_command[i] == ' ') i++;
    if (i == strlen(_command)) return false;
    return true;
}

char **split_command(char *_command, char *_token) {
    int i = 0;
    char **args = NULL;
    char *command_cpy = (char *) malloc((strlen(_command) + 1) * sizeof(char));
    strcpy(command_cpy,_command);
    command_cpy = strtok(command_cpy, _token);
    while (command_cpy != NULL) {
        args = (char **) realloc(args, (i + 1) * sizeof(char *) + 1);
        args[i] =  (char *) malloc((strlen(command_cpy) + 1) * sizeof(char));
        strcpy(args[i], command_cpy);
        command_cpy = strtok(NULL, _token);
        i++;
    }
    clean((void **) &command_cpy);
    return args;
}

void check_exit(char *_command) {
    char **command_split = split_command(_command, " ");
    if (command_split != NULL && (strcmp(command_split[0], "exit")) == 0) exit(0);
}