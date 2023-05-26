#include "commandline.service.h"


char *get_credentials() {
    char hostname[HOST_NAME_MAX + 1];
    if (gethostname(hostname, sizeof(hostname)) == -1) {
        return NULL;
    }

    char *username = getenv("USER");
    if (username == NULL) {
        return NULL;
    }

    char *credentials = (char *) malloc((strlen(username) + strlen(hostname) + 2) * sizeof(char));
    if (credentials == NULL) {
        return NULL;
    }

    snprintf(credentials, strlen(username) + strlen(hostname) + 2, "%s@%s", username, hostname);
    return credentials;
}

void get_command_line(char **_buffer) {
    *_buffer = malloc_command_line();
    fgets(*_buffer, ARG_MAX, stdin);
    (*_buffer)[strcspn(*_buffer, "\n")] = 0;
    *_buffer = realloc_command_line(*_buffer, strlen(*_buffer));
}

bool check_command(char *_command) {
    if (_command == NULL) return false;
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
    clean((void **) &arg);
    return n_args;
}

char **split_command(char *_command, char *_token, int *_n_args) {
    int i = 0;
    *_n_args = get_args_quantity(_command, _token);
    char *arg = strtok(strdup(_command), _token);
    char **args = (char **) malloc((*_n_args + 1) * sizeof(char *));
    args[*_n_args] = NULL;
    while (arg != NULL) {
        args[i] = strdup(arg);
        arg = strtok(NULL, _token);
        i++;
    }
    clean((void **) &arg);
    return args;
}

void check_exit(char *_first_arg) {
    char *trim_arg = strdup(_first_arg);
    if (strncmp(trim(trim_arg), "exit", 4) == 0) {
        exit(0);
    }
}

char *get_command_path(char *_command) {
    char *which = {"which"};
    char *cmd = (char *) malloc((strlen(which) + strlen(_command) + 2) * sizeof(char));
    sprintf(cmd, "%s %s", which, _command);

    FILE *fp = popen(cmd, "r");
    if (fp == NULL) return NULL;

    which = NULL;
    clean((void **) &cmd);
    char *path = (char *) malloc(PATH_MAX * sizeof(char));

    if (fgets(path, PATH_MAX, fp) == NULL) {
        clean((void **) &path);
    } else {
        path[strcspn(path, "\n")] = 0;
    }

    pclose(fp);

    return path;
}

void replace_command(char *_dest, char *_src) {
    if (check_command(_src)) {
        _dest = realloc_command_line(_dest, strlen(_src));
        strcpy(_dest, _src);
        clean((void **) &_src);
    }
}

char **get_redirects_order(const char *_command) {
    int i = 0, add = 1;
    char **redir_order = {NULL};
    while (*_command != 0) {
        if (*_command == '<' || *_command == '>') {
            redir_order = (char **) realloc(redir_order, (i + 2) * sizeof(char *));
            if (*(_command + 1) == *_command && *_command == '>') {
                add = 2;
            }
            redir_order[i] = (char *) malloc((add + 1) * sizeof(char));
            redir_order[i][0] = *_command;
            if(add == 2) {
                redir_order[i][1] = *(_command + 1);
            }
            redir_order[i][add] = 0;
            redir_order[++i] = NULL;
        }
        _command += add;
        add = 1;
    }

    return redir_order;
}

char *trim(char *_str) {
    int length = (int) strlen(_str);
    int i, j;
    for (i = j = 0; i < length; i++) {
        if (!isspace((unsigned char) _str[i])) {
            _str[j++] = _str[i];
        }
    }
    _str[j] = '\0';
    return _str;
}