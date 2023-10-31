// motor_jogo.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define GRID_WIDTH 80
#define GRID_HEIGHT 30
#define NUM_PLAYERS 3

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

    fread(grid, file_size, 1, file);
    grid[file_size] = '\0';
    fclose(file);

    // Lógica principal do motor do jogo...
    // Lógica para interação dos jogadores, detecção de colisões, condições de vitória, etc.
    // ...

    free(grid);

    return 0;
}
