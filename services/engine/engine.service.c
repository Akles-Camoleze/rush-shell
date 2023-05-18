#include "engine.service.h"

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