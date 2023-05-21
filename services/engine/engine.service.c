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

void redirect_setup(char **_redirects, const char *_redir_order, int _n_redir_args) {
    for (int j = 1; j < _n_redir_args; j++) {
        FILE *fp;
        trim(_redirects[j]);
        if(_redir_order[j - 1] == '<') {
            fp = file_handler(_redirects[j], "r");
            dup2(fileno(fp), STDIN_FILENO);
        } else {
            fp = file_handler(_redirects[j], "w");
            dup2(fileno(fp), STDOUT_FILENO);
        }
        close(fileno(fp));
    }
}