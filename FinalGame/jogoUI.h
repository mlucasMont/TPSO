#ifndef JOGO_UI_H
#define JOGO_UI_H

#include "motor_jogo.h"

struct Credentials {
    char username[20];
    char password[20];
};

struct Command {
    char name[MAX_COMMAND_LENGTH];
    // outros parâmetros do comando
};

// Declarar outras estruturas de dados e constantes simbólicas necessárias

#endif
