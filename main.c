#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "services/commandline/commandline.service.h"
#include "views/messages/messages.view.h"
#include "services/file/file.service.h"
#include "services/engine/engine.service.h"


int main() {
    int n_args;
    char *command = NULL;

    while (1) {
        clean((void **) &command);
        get_message("$ ", false);
        get_command_line(&command);
        if (check_command(command)) {
            char **commands = split_command(command, "|", &n_args);
            check_exit(*commands);


            int n_pipes = n_args - 1;
            int pipes[n_pipes][2];
            pid_t p_ids[n_args];
            open_pipes(pipes, n_pipes);

            for (int i = 0; i < n_args; i++) {
                p_ids[i] = fork();
                if (p_ids[i] == 0) {
                    int *pipe = NULL;
                    if (i != 0) {
                        pipe = pipes[i - 1];
                    }
                    pipe_setup(pipes[i], pipe, commands[i + 1]);

                    int n_redir_out;
                    char **redirects = split_command(commands[i], "<", &n_redir_out);
                    replace_command(*redirects, get_command_path(*redirects));
                    for (int j = 1; j < n_redir_out; j++) {
                        FILE *fp = file_handler(redirects[j], "r");
                        dup2(fileno(fp), STDIN_FILENO);
                        close(fileno(fp));
                    }

                    for (int j = 0; j < n_args; i++) {
                        clean((void **) &redirects[j]);
                    }

                    int n_redir_in;
                    redirects = split_command(commands[i], ">", &n_redir_in);
                    replace_command(*redirects, get_command_path(*redirects));
                    for (int j = 1; j < n_redir_in; j++) {
                        FILE *fp = file_handler(redirects[j], "w");
                        dup2(fileno(fp), STDOUT_FILENO);
                        close(fileno(fp));
                    }

                    close_pipes(pipes, n_pipes);
                    char *teste[] = {*redirects, NULL};
                    execvp(*teste, teste);
                    get_message(*teste, true);
                    exit(EXIT_FAILURE);
                }
            }
            close_pipes(pipes, n_pipes);
            waitpid(p_ids[n_args - 1], NULL, 0);

            for (int i = 0; i < n_args; ++i) {
                clean((void **) &commands[i]);
            }
        }
    }
    return 0;
}