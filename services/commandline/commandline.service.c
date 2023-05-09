#include "commandline.service.h"

void get_command_line(char **_buffer) {
    *_buffer = malloc_command_line();
    fgets(*_buffer, ARG_MAX, stdin);
    (*_buffer)[strcspn(*_buffer, "\n")] = 0;
    *_buffer = realloc_command_line(*_buffer);
}

bool check_command(char *_command) {
    int i = 0;
    while (_command[i] == ' ') i++;
    if (i == strlen(_command)) return false;
    return true;
}

int get_args_quantity(char *_command, char *_token) {
    int n_args = 0;
    char *arg = strtok(strdup(_command), _token);
    while (arg != NULL) {
        n_args++;
        arg = strtok(NULL, _token);
    }
    clean((void **)&arg);
    return n_args;
}

char **split_command(char *_command, char *_token) {
    int i = 0;
    int n_args = get_args_quantity(_command, _token);
    char *arg = strtok(strdup(_command), _token);
    char **args = (char **) malloc((n_args + 1) * sizeof(char *));
    args[n_args] = NULL;
    while (arg != NULL) {
        args[i] = strdup(arg);
        arg = strtok(NULL, _token);
        i++;
    }
    clean((void **) &arg);
    return args;
}

void check_exit(char *_first_arg) {
    if (strcmp(_first_arg, "exit") == 0){
        exit(0);
    }
}