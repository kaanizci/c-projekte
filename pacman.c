#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // für usleep
#include <termios.h> // für Terminal-Modus (raw input)
#include <string.h>
#include <time.h>    // <-- WICHTIG: Für time()

#define WIDTH 40
#define HEIGHT 20
#define PACMAN 'C'
#define WALL '#'
#define FOOD '.'
#define EMPTY ' '
#define DEMON 'X'

// globale Variablen
int score = 0;
int food = 0, curr = 0;
int pacman_x, pacman_y;
int res = 0;
char board[HEIGHT][WIDTH];

// Terminaleinstellungen speichern
struct termios orig_termios;

// Terminal in raw-Modus setzen
void enable_raw_mode() {
    tcgetattr(STDIN_FILENO, &orig_termios);
    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

// Terminal zurücksetzen
void disable_raw_mode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

// Bildschirm löschen (ANSI-Escape-Code)
void clear_screen() {
    printf("\033[H\033[J");
}

// Spiel initialisieren
void initialize() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || j == WIDTH - 1 || j == 0 || i == HEIGHT - 1)
                board[i][j] = WALL;
            else
                board[i][j] = EMPTY;
        }
    }

    // zufällige Wände
    for (int count = 0; count < 50; ) {
        int i = rand() % HEIGHT;
        int j = rand() % WIDTH;
        if (board[i][j] == EMPTY) {
            board[i][j] = WALL;
            count++;
        }
    }

    // Dämonen
    for (int count = 0; count < 10; ) {
        int i = rand() % HEIGHT;
        int j = rand() % WIDTH;
        if (board[i][j] == EMPTY) {
            board[i][j] = DEMON;
            count++;
        }
    }

    // Pacman Startposition
    pacman_x = WIDTH / 2;
    pacman_y = HEIGHT / 2;
    board[pacman_y][pacman_x] = PACMAN;

    // Futter setzen
    for (int i = 1; i < HEIGHT - 1; i++) {
        for (int j = 1; j < WIDTH - 1; j++) {
            if ((i % 2 == 0 || j % 2 == 0) && board[i][j] == EMPTY) {
                board[i][j] = FOOD;
                food++;
            }
        }
    }
}

// Spielfeld anzeigen
void draw() {
    clear_screen();
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
}

// Bewegung von Pacman
void move(int dx, int dy) {
    int x = pacman_x + dx;
    int y = pacman_y + dy;

    if (board[y][x] == WALL)
        return;

    if (board[y][x] == DEMON) {
        res = 1;
        return;
    }

    if (board[y][x] == FOOD) {
        score++;
        curr++;
        food--;
        if (food == 0) {
            res = 2;
            return;
        }
    }

    board[pacman_y][pacman_x] = EMPTY;
    pacman_x = x;
    pacman_y = y;
    board[pacman_y][pacman_x] = PACMAN;
}

// Hauptfunktion
int main() {
    srand((unsigned int) time(NULL));
    enable_raw_mode(); // Eingabe ohne ENTER
    atexit(disable_raw_mode); // Rücksetzung bei Programmende

    initialize();

    printf("Willkommen zu PACMAN\n");
    printf("Benutze W A S D für Bewegung, Q für Beenden.\n");
    printf("Drücke eine Taste zum Starten...\n");
    getchar();

    while (1) {
        draw();

        if (res == 1) {
            printf("\n💀 Von einem Dämon getroffen! GAME OVER.\n");
            break;
        }

        if (res == 2) {
            printf("\n🎉 Alle Punkte gegessen! DU GEWONNEN!\n");
            break;
        }

        char ch = getchar();
        switch (ch) {
            case 'w': move(0, -1); break;
            case 's': move(0, 1); break;
            case 'a': move(-1, 0); break;
            case 'd': move(1, 0); break;
            case 'q': printf("Spiel beendet. Dein Punktestand: %d\n", score); return 0;
        }
        usleep(100000); // kurze Pause für bessere Sichtbarkeit
    }

    return 0;
}