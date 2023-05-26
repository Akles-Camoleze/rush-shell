#ifndef RUSH_SHELL_FILE_SERVICE_H
#define RUSH_SHELL_FILE_SERVICE_H

#include <stdio.h>
#include <stdlib.h>
#include "../../views/messages/messages.view.h"

/**
 *  Manipulador para abertura de arquivos
 * @param _file_name :Nome do arquivo a ser fechado
 * @param _mode :Modo que o arquivo deve ser aberto
 * @return char* com os redirecionadores contidos em _command em ordem
 */
FILE *file_handler(char *_file_name, char *_mode);

#endif //RUSH_SHELL_FILE_SERVICE_H
