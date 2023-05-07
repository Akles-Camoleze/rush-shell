#include "messages.view.h"

void get_message(char *msg, bool error) {
    //Verificacao se a mensagem é um erro
    error ? perror(msg) : printf("\n%s", msg);
}
