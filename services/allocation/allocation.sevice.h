#ifndef RUSH_SHELL_ALLOCATION_SEVICE_H

#define RUSH_SHELL_ALLOCATION_SEVICE_H

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <linux/limits.h>

/**
 * Aloca memória de acordo com do sistema(ARG_MAX)
 * @return
 * Nova posicao de string alocada
 * */
char *malloc_command_line();

/**
 * Realoca de acordo com o tamanho de _command
 * @param _command: Endereço do ponteiro para a string que sera realocada
 * @return
 * Nova posicao de string realocada
 * */
char *realloc_command_line(char *_command);

#endif //RUSH_SHELL_ALLOCATION_SEVICE_H
