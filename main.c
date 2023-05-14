#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
#include "services/commandline/commandline.service.h"
#include "views/messages/messages.view.h"

#define W 1
#define R 0
#define A 0
#define B 1

int main() {
    char *command = NULL;

    while (1) {
        clean((void **) &command);
        get_message("$ ", false);
        get_command_line(&command);
        bool checked = check_command(command);
        if (checked) {
            int n_args;
            char **command_split = split_command(command, "|", &n_args); // matriz do split em pipe
            check_exit(*command_split);
            int pipes[2][2];
            pipe(pipes[A]);
            pipe(pipes[B]);
            pid_t p_ids[n_args];

            for (int i = 0; i < n_args; i++) {
                char *command_path = get_command_path(command_split[i]);
                if (check_command(command_path)) {
                    command_split[i] = realloc_command_line(command_split[i], strlen(command_path));
                    strcpy(command_split[i], command_path);
                    clean((void **) &command_path);
                }
                printf("\n%s", command_split[i]);
                if (i >= 3) {
                    waitpid(p_ids[i - 3], NULL, 0);
                }
                p_ids[i] = fork();
                if (p_ids[i] == 0) {
                    if (i == 0) {
                        dup2(pipes[A][W], STDOUT_FILENO);
                    } else {
                        dup2(pipes[(i - 1) % 2][R], STDIN_FILENO);
                        if (command_split[i + 1] != NULL) {
                            dup2(pipes[i % 2][W], STDOUT_FILENO);
                        }
                    }
                    char *teste[] = {command_split[i], NULL};
                    close(pipes[A][R]);
                    close(pipes[A][W]);
                    close(pipes[B][R]);
                    close(pipes[B][W]);
                    execvp(command_split[i], teste);
                    get_message(command_split[i], true);
                    exit(EXIT_FAILURE);
                }
                waitpid(p_ids[(i + 1) % 2], NULL, 0);
            }
            close(pipes[B][W]);
            close(pipes[B][R]);
            close(pipes[A][R]);
            close(pipes[A][W]);
            waitpid(p_ids[n_args - 1], NULL, 0);
            for (int i = 0; i < n_args; ++i) {
                clean((void**) &command_split[i]);
            }
        }
    }
    return 0;
}
