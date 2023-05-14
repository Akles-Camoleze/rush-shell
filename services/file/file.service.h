#ifndef RUSH_SHELL_FILE_SERVICE_H
#define RUSH_SHELL_FILE_SERVICE_H

#include <stdio.h>
#include <stdlib.h>
#include "../../views/messages/messages.view.h"

FILE *file_handler(char *_file_name, char *_mode);

void close_file(FILE *_fp);

#endif //RUSH_SHELL_FILE_SERVICE_H
