#ifndef RUSH_SHELL_EXCEPTIONS_H
#define RUSH_SHELL_EXCEPTIONS_H

#include <stdio.h>
#include "../views/messages/messages.view.h"
#define ERR_LOG_FILE "../error.log"

void save_in_log(char *_fd_name, char *_message);

#endif //RUSH_SHELL_EXCEPTIONS_H
