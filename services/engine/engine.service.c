#include "engine.service.h"
#include "../commandline/commandline.service.h"

void open_pipes(int _pipes[][2], int _n_pipes) {
    for (int i = 0; i < _n_pipes; i++) {
        if (pipe(_pipes[i]) == -1) {
            get_message("Pipe", true);
            exit(EXIT_FAILURE);
        }
    }
}

void close_pipes(int _pipes[][2], int _n_pipes) {
    for (int i = 0; i < _n_pipes; i++) {
        close(_pipes[i][R]);
        close(_pipes[i][W]);
    }
}

void pipe_setup(int *_curr_pipe, int *_prev_pipe, const char *_next_cmd) {
    if (_next_cmd != NULL) {
        dup2(_curr_pipe[W], STDOUT_FILENO);
    }
    if (_prev_pipe != NULL) {
        dup2(_prev_pipe[R], STDIN_FILENO);
    }
}

void redirect_setup(char **_redirects, char **_redir_order, int _n_redir_args) {
    for (int j = 1; j < _n_redir_args; j++) {
        FILE *fp = NULL;
        trim(_redirects[j]);
        if (strcmp(_redir_order[j - 1], "<") == 0) {
            fp = file_handler(_redirects[j], "r");
            dup2(fileno(fp), STDIN_FILENO);
        } else {
            char *mode = "a";
            if (strcmp(_redir_order[j - 1], ">") == 0) {
                mode = "w";
            }
            fp = file_handler(_redirects[j], mode);
            dup2(fileno(fp), STDOUT_FILENO);
        }
        close(fileno(fp));
    }
}

void exec_command(char **_commands, int _n_cmd) {
    int n_pipes = _n_cmd - 1;
    int pipes[n_pipes][2];
    pid_t p_ids[_n_cmd];
    open_pipes(pipes, n_pipes);

    for (int i = 0; i < _n_cmd; i++) {
        p_ids[i] = fork();
        if (p_ids[i] == 0) {
            int *prev_pipe = NULL;
            if (i != 0) {
                prev_pipe = pipes[i - 1];
            }
            pipe_setup(pipes[i], prev_pipe, _commands[i + 1]);
            close_pipes(pipes, n_pipes);

            int n_redir_args;
            char **redir_order = get_redirects_order(_commands[i]);
            char **redirects = split_command(_commands[i], DUP_TOK, &n_redir_args);
            int n_spaces;
            char **spaces = split_command(*redirects, SPACE_TOK, &n_spaces);

            replace_command(*spaces, get_command_path(*spaces));
            redirect_setup(redirects, redir_order, n_redir_args);

            execvp(*spaces, spaces);
            get_message(*spaces, true);
            exit(EXIT_FAILURE);
        }
    }
    close_pipes(pipes, n_pipes);
    waitpid(p_ids[_n_cmd - 1], NULL, 0);
    n_clean((void **)_commands, _n_cmd);
}