#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "services/commandline/commandline.service.h"
#include "views/messages/messages.view.h"

int main() {
    char *command = NULL;
    while (1) {
        free(command);
        command = NULL;
        get_message("\033[35;1mrush@shell\033[37;1m:\033[32m~\033[37m$ ", false);
        get_command_line(&command);
        bool checked = check_command(command);
        if (checked) {
            get_message(strcat(command, "\n"), false);
        }
    }

    return 0;
}
