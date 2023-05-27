#include <stdio.h>
#include <string.h>
#include "services/commandline/commandline.service.h"
#include "views/messages/messages.view.h"
#include "services/engine/engine.service.h"

int main() {
    int n_cmd;
    char *command = NULL;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
    while (true) {
        clean((void **) &command);
        printf("\033[35;1m%s\033[37;1m:\033[32m~\033[37m$ ", get_credentials());
        get_command_line(&command);
        if (check_command(command)) {
            char **commands = split_command(command, PIPE_TOK, &n_cmd);
            check_exit(*commands);
            exec_command(commands, n_cmd);
        }
    }
#pragma clang diagnostic pop
    return 0;
}