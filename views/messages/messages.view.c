#include "messages.view.h"

void get_message(char *msg, bool error) {
    error ? perror(msg) : printf("\n%s", msg);
}