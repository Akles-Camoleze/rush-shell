#ifndef RUSH_SHELL_COMMANDLINE_SERVICE_H
#define RUSH_SHELL_COMMANDLINE_SERVICE_H

#include "../allocation/allocation.sevice.h"
#include "../../views/messages/messages.view.h"
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>
#include <limits.h>

char *get_credentials();

/**
 * Recebe o comando no endereço apontado por _buffer
 * @param _buffer :Endereço do ponteiro para a string onde deve ser salvo o comando
 */
void get_command_line(char **_buffer);

/**
 * Verifica se _command é válido para ser executado
 * @param _command :Comando à ser executado
 * @return true caso o comando seja válido, false caso seja inválido
 */
bool check_command(char *_command);

/**
 *  Executa a função "exit(0)" para "fechar" o processo pai.
 * @param _command : argumento (_args)  esperando ser exit
 * @return void :sem retorno
 */
void check_exit(char *_command);

/**
 *  Calcula a quantidade de argumentos presente em _command de acordo com _token.
 * @param _command :Comando à se calcular o número de argumentos
 * @param _token: Delimitador no qual o _command deve ser explodido
 * @return Número de argumentos em _command
 */
int get_args_quantity(char *_command, char *_token);

/**
 *  Explode o _command em argumentos de acordo com _token
 * @param _command :Comando a ser realizada a explosão
 * @param _token: Delimitador no qual o _command deve ser explodido
 * @return Matriz de argumentos, presente em _command
 */
char **split_command(char *_command, char *_token, int *_n_args);

/**
 *  Obtem o caminho (path) do _commando
 * @param _command :Comando a ser obtido o caminho
 * @return caminho de _command
 */
char *get_command_path(char *_command);

void replace_command(char *_dest, char *_src);

char *get_redirects_order(const char *_command);

char *trim(char *_str);

#endif //RUSH_SHELL_COMMANDLINE_SERVICE_H
