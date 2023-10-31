// jogoUI.c
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#define GRID_WIDTH 80
#define GRID_HEIGHT 30

// Função para imprimir o labirinto na tela usando NCurses
void printLab(const char *grid) {
    initscr(); // Inicializa NCurses
    raw();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);

    int x, y;
    int i;
    for (i = 0; i < GRID_WIDTH * GRID_HEIGHT; i++) {
        y = i / GRID_WIDTH;
        x = i % GRID_WIDTH;

        if (grid[i] == 'X') {
            mvaddch(y, x, 'X');
        } else if (grid[i] == ' ') {
            mvaddch(y, x, ' ');
        }
    }

    refresh(); // Atualiza a tela

    // Lógica para interação do jogador e atualização do jogo na interface...
    while (1) {
        // Lógica para lidar com a entrada do jogador e atualização da interface
        // ...
    }

    endwin(); // Finaliza a NCurses
}

void getCredentials(struct Credentials *credentials) {
    // Lógica para receber as credenciais do utilizador
}

int validateCommand(struct Command *command) {
    // Lógica para validar os comandos
}

int main() {
    FILE *file = fopen("labirinto.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo do labirinto.\n");
        return 1;
    }

    struct Credentials userCredentials;
    getCredentials(&userCredentials);

    struct Command userCommand;
    // Lógica para ler comandos do utilizador e validá-los
    while (1) {
        // Ler comando e validar
        // Exemplo de como chamar a função de validação:
        if (validateCommand(&userCommand)) {
            // Comando válido
        } else {
            // Comando inválido
        }
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

    fread(grid, file_size, 1, file);
    grid[file_size] = '\0';
    fclose(file);

    printLab(grid);

    free(grid);

    return 0;
}
