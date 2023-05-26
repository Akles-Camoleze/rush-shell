#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "services/commandline/commandline.service.h"
#include "views/messages/messages.view.h"
#include "services/file/file.service.h"
#include "services/engine/engine.service.h"


int main() {
    int n_cmd;
    char *command = NULL;

    while (true) {
        clean((void **) &command);
        printf("\033[35;1m%s\033[37;1m:\033[32m~\033[37m$ ", get_credentials());
        get_command_line(&command);
        if (check_command(command)) {
            char **commands = split_command(command, PIPE_TOK, &n_cmd);
            check_exit(*commands);

            int n_pipes = n_cmd - 1;
            int pipes[n_pipes][2];
            pid_t p_ids[n_cmd];
            open_pipes(pipes, n_pipes);

            for (int i = 0; i < n_cmd; i++) {
                p_ids[i] = fork();
                if (p_ids[i] == 0) {
                    int *prev_pipe = NULL;
                    if (i != 0) {
                        prev_pipe = pipes[i - 1];
                    }
                    pipe_setup(pipes[i], prev_pipe, commands[i + 1]);
                    close_pipes(pipes, n_pipes);

                    int n_redir_args;
                    char **redir_order = get_redirects_order(commands[i]);
                    char **redirects = split_command(commands[i], DUP_TOK, &n_redir_args);
                    int n_spaces;
                    char **spaces = split_command(*redirects, SPACE_TOK, &n_spaces);

                    replace_command(*spaces, get_command_path(*spaces));
                    redirect_setup(redirects, redir_order, n_redir_args);

                    execvp(*spaces, spaces);
                    get_message(*spaces, true);
                    exit(EXIT_FAILURE);
                }
            }
            close_pipes(pipes, n_pipes);
            waitpid(p_ids[n_cmd - 1], NULL, 0);

            for (int i = 0; i < n_cmd; ++i) {
                clean((void **) &commands[i]);
            }
        }
    }
    return 0;
}