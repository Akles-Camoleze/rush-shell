#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
#include "services/commandline/commandline.service.h"
#include "views/messages/messages.view.h"
#define WRITE 1
#define READ 0

int main() {
    char *command = NULL;
    int *pipeA = NULL;
    pipe(pipeA);
    pid_t pid;
    char *test[] = {"ll", NULL};

    while (1) {
        free(command);
        command = NULL;
        get_message("\033[35;1mrush@shell\033[37;1m:\033[32m~\033[37m$ ", false);
        get_command_line(&command);
        bool checked = check_command(command);
        if (checked) {
            char **command_split = split_command(command, " ");
            check_exit(*command_split);
            pid = fork();
            if (pid == 0) {
                execvp(*command_split, command_split);
               get_message(*command_split, true);
                exit(1);
            } else {
                wait(NULL);
            }
        }
    }

    return 0;
}
