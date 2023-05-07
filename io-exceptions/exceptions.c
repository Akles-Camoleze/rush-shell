#include "exceptions.h"

void save_in_log(char *_fd_name, char *_msg) {
    FILE *fd;
    if((fd = fopen(_fd_name, "a")) != NULL) {
        fprintf(fd, "%s", _msg);
    }
}