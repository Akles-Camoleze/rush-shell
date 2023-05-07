#include "messages.view.h"

/**
 * Exibe mensagem de acordo com criterio de erro definido em _error
 * @param _msg: Endereço da mensagem a ser exibida
 * @param _error: flag que indica se _msg é uma mensagem de erro
 * */
void get_message(char *_msg, bool _error) {
    _error ? perror(_msg) : printf("\n%s", _msg);
}
