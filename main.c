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
    int pipes[2][2];
    /*
     * n % 2 == 0: PipeA
     * n % 2 == 1: PipeB
     * [
     *      0: PipeA = []
     *      1: PipeB = []
     * ]
     */
    pid_t p_ids[1000];
    char *command_path;
    pipe(pipes[A]);
    pipe(pipes[B]);
    char *test1[] = {"/usr/bin/ls", NULL};
    char *test2[] = {"/usr/bin/wc", NULL};

    while (1) {
        free(command);
        command = NULL;
        get_message("\033[35;1mrush@shell\033[37;1m:\033[32m~\033[37m$ ", false);
        get_command_line(&command);
        bool checked = check_command(command);

        if (checked) {
            // explode em pipe
            int n_args;
            char **command_split = split_command(command, "|", &n_args); // matriz do split em pipe
            check_exit(*command_split);

            // recebe caminho do programa
            command_path = get_command_path(*command_split);
            if (check_command(command_path)) {
                *command_split = realloc_command_line(*command_split, strlen(command_path));
                strcpy(*command_split, command_path);
                clean((void **) &command_path);
            }


            // inicia split em dup
            char **command_dup;
            for (int i = 0; i < n_args; ++i) {
                int n_dup_args;
                command_dup = split_command(command_split[i], ">", &n_dup_args);

                // inicia split em space
                char **command_space;
                for (int j = 0; j < n_dup_args; ++j) {
                    int n_space_args;
                    command_space = split_command(command_dup[i], " ", &n_space_args);
                    p_ids[0] = fork();
                    if (p_ids[0] == 0) {
                        execvp(*command_space, command_space);
                    }
                }
            }
        }
        wait(NULL);
    }
    return 0;
}
