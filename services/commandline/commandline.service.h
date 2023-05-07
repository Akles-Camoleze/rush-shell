#ifndef RUSH_SHELL_COMMANDLINE_SERVICE_H
#define RUSH_SHELL_COMMANDLINE_SERVICE_H

#include "../allocation/allocation.sevice.h"
#include <stdbool.h>

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

#endif //RUSH_SHELL_COMMANDLINE_SERVICE_H
