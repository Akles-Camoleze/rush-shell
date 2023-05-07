#include "messages.view.h"

void get_message(char *_msg, bool _error) {
    _error ? perror(_msg) : printf("\n%s", _msg);
}
