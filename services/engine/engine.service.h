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

/**
 *  Realiza abertura de _n_pipes
 * @param _pipes :Pipes a serem abertos
 * @param _n_pipes :Numero de pipes a serem abertos
 */
void open_pipes(int _pipes[][2], int _n_pipes);

/**
 *  Realiza fechamento de _n_pipes
 * @param _pipes :Pipes a serem fechados
 * @param _n_pipes :Numero de pipes a serem fechados
 */
void close_pipes(int _pipes[][2], int _n_pipes);

/**
 *  Realiza configuração dos pipes: Amarra as pontas de leitura e escrita com base nos valores de
 *  _prev_pipe e _next_cmd
 * @param _curr_pipe :Pipe atual
 * @param _prev_pipe :Pipe anterior
 * @param _next_cmd :Proximo comando a ser executado
 */
void pipe_setup(int *_curr_pipe, int *_prev_pipe, const char *_next_cmd);

/**
 *  Realiza configuração dos dups: Amarra as pontas de leitura e escrita com base nos valores de
 *  _redir_order
 * @param _redirects :matriz que contem os comandos separados por '<', '>' ou '>>'
 * @param _redir_order :matriz que contem a ordem que '<', '>' e '>>' ocorrem
 * @param _n_redir_args :numero de redirecionadores encontrado
 */
void redirect_setup(char **_redirects, char **_redir_order, int _n_redir_args);

/**
 *  Realiza a execução do comando
 * @param _commands :Comandos a serem executados
 * @param _n_cmd :Quantidade de comandos
 */
void exec_command(char **_commands, int _n_cmd);

#endif //RUSH_SHELL_ENGINE_SERVICE_H
