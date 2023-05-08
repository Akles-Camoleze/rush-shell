#include "allocation.sevice.h"

char *malloc_command_line() {
    return (char *) malloc(ARG_MAX * sizeof(char));
}

char *realloc_command_line(char *_command) {
    return (char *) realloc(_command, (strlen(_command) + 1) * sizeof(char));
}

void clean(void **_ptr) {
    free(*_ptr);
    *_ptr = NULL;
}