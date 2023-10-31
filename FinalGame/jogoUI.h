#ifndef JOGO_UI_H
#define JOGO_UI_H

#include "motor_jogo.h"

struct Credentials {
    char username[20];
};

struct Command {
    char name[MAX_COMMAND_LENGTH];
    char users;
    char kick;
    char bots;
    char bmov;
    char rbm;
    char begin;
    char end;
    // outros parâmetros do comando
};

// Declarar outras estruturas de dados e constantes simbólicas necessárias
void sendPlayerInfoToMotor(const char *playerName);
void receiveMessageFromMotor();
void printLab(const char *grid);
void getCredentials(struct Credentials *credentials);
int validateCommand(struct Command *command);

#endif
