#ifndef MOTOR_H
#define MOTOR_H

#define MAX_BOT_MESSAGES 100
#define MAX_COMMAND_LENGTH 50

#include "jogoUI.h"

#define GRID_WIDTH 80
#define GRID_HEIGHT 30
#define NUM_PLAYERS 3

#define PIPE_NAME "jogo_pipe"

struct BotMessage {
    char content[MAX_COMMAND_LENGTH];
};

struct Coordinates {
    int x;
    int y;
};

struct CommandAdmin {
    char name[MAX_COMMAND_LENGTH];
    // outros parâmetros do comando
};

// Declarar outras estruturas de dados e constantes simbólicas necessárias

#endif
