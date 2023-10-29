#include <ncurses.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Define o tamanho da grade
#define GRID_WIDTH 80
#define GRID_HEIGHT 30

char *jogador;

// Função para verificar se uma posição contém um obstáculo ('#')
int is_obstacle(int x, int y, const char *grid) {
    if (x < 0 || x >= GRID_WIDTH || y < 0 || y >= GRID_HEIGHT) {
        return 1; // Fora dos limites da grade é considerado um obstáculo
    }
    return grid[y * GRID_WIDTH + x] == '#';
}

int is_Fim(int x, int y, const char *grid) {
    if (x < 0 || x >= GRID_WIDTH || y < 0 || y >= GRID_HEIGHT) {
        return 0; // Fora dos limites da grade não é o fim
    }
    return grid[y * GRID_WIDTH + x] == 'F';
}

// Função para imprimir o labirinto
void printLab(const char *labirinto, int playerX, int playerY, char playerSymbol) {
    initscr(); // Inicializa NCurses
    raw();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0); // Oculta o cursor

    int x, y;
    int i;
    for (i = 0; i < GRID_WIDTH * GRID_HEIGHT; i++) {
        y = i / GRID_WIDTH;
        x = i % GRID_WIDTH;

        if (labirinto[i] == '#') {
            mvaddch(y, x, '#');
        } else if (labirinto[i] == ' ') {
            mvaddch(y, x, ' ');
        }
    }

    refresh(); // Atualiza a tela

    while (1) {
        int ch = getch();
        if (ch == 'q' || ch == 'Q') {
            break;
        }

        int new_x = playerX;
        int new_y = playerY;

        if (ch == KEY_RIGHT) {
            new_x++;
        } else if (ch == KEY_LEFT) {
            new_x--;
        } else if (ch == KEY_UP) {
            new_y--;
        } else if (ch == KEY_DOWN) {
            new_y++;
        }

        if (!is_obstacle(new_x, new_y, labirinto)) {
            mvaddch(playerY, playerX, ' '); // Apaga a posição anterior do jogador
            playerX = new_x;
            playerY = new_y;
            mvaddch(playerY, playerX, playerSymbol); // Desenha o jogador na nova posição
            refresh();
        }

        if (is_Fim(playerX, playerY, labirinto)) {
            mvprintw(GRID_HEIGHT + 1, 0, "Parabéns! %s chegou ao fim!!!", jogador);
            refresh();
            break;
        }
    }

    getch(); 
    endwin();
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <nome do jogador>\n", argv[0]);
        return 1;
    }

    jogador = strdup(argv[1]);

    const char *grid =
        "################################################################################"
        "#            #                                                                 #"
        "#            #                        ##########################################"
        "#### #########                                                                 #"
        "#            #                                                                 #"
        "#            #               ################################################# #"
        "#    #####   #                                                                 #"
        "#            ################                                                  #"
        "###########  #                 ######################                          #"
        "#                                                                              #"
        "#                              ############################################### #"
        "#                                                                              #"
        "################                              ######################           #"
        "#                                                                              #"
        "#                                   ######################                     #"
        "# ###############         ###                                                  #"
        "#                      #     #                   ######################        #"
        "#                      #     #                                                 #"
        "###########################FF###################################################";

    int playerX = 1; // Posição inicial do jogador
    int playerY = 1;
    char playerSymbol = *jogador;

    printLab(grid, playerX, playerY, playerSymbol);
    free(jogador);
    return 0;
}
