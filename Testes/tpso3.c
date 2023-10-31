#include <ncurses.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <nome do jogador>\n", argv[0]);
        return 1;
    }

    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();

    int ch;
    int x = 0, y = 0;

    char *jogador = argv[1]; // Obtem o nome do jogador a partir dos argumentos
    char simbolo = jogador[0]; // Pega a primeira letra do nome

    while (1) {
        ch = getch();
        mvaddch(y, x, ' ');
        refresh();

        if (ch == KEY_RIGHT) {
            x++;
        } else if (ch == KEY_LEFT) {
            x--;
        } else if (ch == KEY_UP) {
            y--;
        } else if (ch == KEY_DOWN) {
            y++;
        } else if (ch == 'q' || ch == 'Q') {
            break;
        }

        mvaddch(y, x, simbolo);
        refresh();
    }

    endwin();
    return 0;
}
