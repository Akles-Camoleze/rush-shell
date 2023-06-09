#include "allocation.service.h"

char *malloc_command_line() {
    return (char *) malloc(ARG_MAX * sizeof(char));
}

char *realloc_command_line(char *_command, size_t _size) {
    return (char *) realloc(_command, (_size + 1) * sizeof(char));
}

void clean(void **_ptr) {
    free(*_ptr);
    *_ptr = NULL;
}

void n_clean(void **_ptr, int _n) {
    for (int i = 0; i < _n; i++) {
        clean((void **) &(_ptr[i]));
    }
}