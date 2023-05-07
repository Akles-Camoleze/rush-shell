#include "allocation.sevice.h"

char *malloc_command_line() {
    //Alocação de memoria, com o tamanho maximo de bytes
    return (char *) malloc(ARG_MAX * sizeof(char));
}

char *realloc_command_line(char **_command) {
    //Realoca de acordo com o tamanho do comando
    return (char *) realloc(*_command, (strlen(*_command) + 1) * sizeof(char));
}