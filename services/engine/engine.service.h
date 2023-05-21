#ifndef RUSH_SHELL_ENGINE_SERVICE_H
#define RUSH_SHELL_ENGINE_SERVICE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include "../../views/messages/messages.view.h"
#include "../file/file.service.h"
#define W 1
#define R 0

void open_pipes(int _pipes[][2], int _n_pipes);

void close_pipes(int _pipes[][2], int _n_pipes);

void pipe_setup(int *_curr_pipe, int *_prev_pipe, const char *_next_cmd);

void redirect_setup(char **_redirects, const char *_redir_order, int _n_redir_args);

#endif //RUSH_SHELL_ENGINE_SERVICE_H
