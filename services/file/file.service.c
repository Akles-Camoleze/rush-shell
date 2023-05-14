#include "file.service.h"

FILE *file_handler(char *_file_name, char *_mode) {
    FILE *fp;
    if ((fp = fopen(_file_name, _mode)) == NULL) {
        get_message("Falha no arquivo", true);
        exit(EXIT_FAILURE);
    }
    return fp;
}

void close_file(FILE *_fp) {
    if (_fp != NULL) fclose(_fp);
}
