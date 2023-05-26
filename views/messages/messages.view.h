#ifndef RUSH_SHELL_MESSAGES_VIEW_H
#define RUSH_SHELL_MESSAGES_VIEW_H

#include <stdbool.h>
#include <stdio.h>

/**
 * Exibe mensagem de acordo com criterio de erro definido em _error
 * @param _msg: Endereço da mensagem a ser exibida
 * @param _error: flag que indica se _msg é uma mensagem de erro
 * */
void get_message(char *_msg, bool _error);

#endif //RUSH_SHELL_MESSAGES_VIEW_H