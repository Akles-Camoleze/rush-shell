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
 * Realoca _command de acordo com o tamanho de _size
 * @param _command: Endereço do ponteiro para a string que sera realocada
 * @param _size: Tamanho de memória a ser realocada
 * @return
 * Nova posicao de string realocada
 * */
char *realloc_command_line(char *_command, size_t _size);

/**
 * Libera o ponteiro da memória e aponta-o para NULL
 * @param _ptr: Ponteiro a ser manipulado
 * */
void clean(void **_ptr);

void clean_set(void **_ptr, int _n);

#endif //RUSH_SHELL_ALLOCATION_SEVICE_H
