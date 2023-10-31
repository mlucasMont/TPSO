// motor_jogo.c
#include "motor_jogo.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define GRID_WIDTH 80
#define GRID_HEIGHT 30
#define NUM_PLAYERS 3

#define PIPE_NAME "jogo_pipe"

int numMessagesOne;

void processUserCommand(const char *command) {
    // Implemente a lógica para processar os comandos do usuário recebidos pelo pipe nomeado
    // Aqui, você lidará com os comandos enviados pelo jogoUI
    printf("Comando recebido do jogoUI: %s\n", command);
    // Realize a lógica do jogo com base no comando recebido
    // Por exemplo, movimento do jogador, ação no jogo, etc.
}

void waitForCommandsFromUI() {
    int fd;
    char commandBuffer[100];

    // Criando o pipe nomeado (FIFO) se não existir
    mkfifo(PIPE_NAME, 0666);

    while (1) {
        // Abrindo o pipe para leitura
        fd = open(PIPE_NAME, O_RDONLY);
        if (fd < 0) {
            perror("Erro ao abrir o pipe");
            exit(1);
        }

        // Lendo o comando enviado pelo jogoUI
        read(fd, commandBuffer, sizeof(commandBuffer));
        close(fd);

        // Processando o comando recebido
        processUserCommand(commandBuffer);
    }
}

// Função para verificar se uma posição contém um obstáculo ('X')
int is_obstacle(int x, int y, const char *grid) {
    if (x < 0 || x >= GRID_WIDTH || y < 0 || y >= GRID_HEIGHT) {
        return 1; // Fora dos limites da grade é considerado um obstáculo
    }
    return grid[y * GRID_WIDTH + x] == 'X';
}

int is_Fim(int x, int y, const char *grid) {
    if (x < 0 || x >= GRID_WIDTH || y < 0 || y >= GRID_HEIGHT) {
        return 0; // Fora dos limites da grade não é o fim
    }
    return grid[y * GRID_WIDTH + x] == 'F';
}

int validateAdminCommand(struct CommandAdmin *adminCommand) {
    // Lógica para validar os comandos do administrador
}

void launchBot() {
    // Lógica para lançar o bot
}

void receiveCoordinates(struct Coordinates *coordinates) {
    // Lógica para receber coordenadas
}

void showBotMessages(struct BotMessage *botMessages, int numMessages) {
    // Lógica para mostrar mensagens do bot
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <arquivo do labirinto>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo do labirinto.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char *grid = (char *)malloc(file_size + 1);
    if (grid == NULL) {
        printf("Erro de alocação de memória.\n");
        fclose(file);
        return 1;
    }

     struct CommandAdmin adminCommand;
    // Lógica para ler e validar comandos do administrador
    while (1) {
        // Ler comando e validar
        // Exemplo de como chamar a função de validação:
        if (validateAdminCommand(&adminCommand)) {
            // Comando válido
            if (strcmp(adminCommand.name, "test_bot") == 0) {
                launchBot();
                struct BotMessage messages[MAX_BOT_MESSAGES];
                // Receber mensagens do bot
                // Mostrar mensagens na tela
                showBotMessages(messages, numMessagesOne);
            }
            // Outros comandos administrativos...
        } else {
            // Comando inválido
        }
    }

    fread(grid, file_size, 1, file);
    grid[file_size] = '\0';
    fclose(file);

    // Lógica principal do motor do jogo...
    // Lógica para interação dos jogadores, detecção de colisões, condições de vitória, etc.
    // ...

    free(grid);

    return 0;
}
