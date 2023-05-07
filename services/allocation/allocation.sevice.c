#include "allocation.sevice.h"


/**
 * Aloca memória de acordo com do sistema(ARG_MAX)
 * @return
 * Nova posicao de string alocada
 * */
char *malloc_command_line() {
    return (char *) malloc(ARG_MAX * sizeof(char));
}

/**
 * Realoca de acordo com o tamanho de _command
 * @param _command: Endereço do ponteiro para a string que sera realocada
 * @return
 * Nova posicao de string realocada
 * */
char *realloc_command_line(char *_command) {
    return (char *) realloc(_command, (strlen(_command) + 1) * sizeof(char));
}