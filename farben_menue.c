#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT 1000

// ANSI-Farbcodes
#define RESET       "\033[0m"
#define BOLD        "\033[1m"

const char* fg_colors[] = {
    "\033[30m", // Schwarz
    "\033[31m", // Rot
    "\033[32m", // Grün
    "\033[33m", // Gelb
    "\033[34m", // Blau
    "\033[35m", // Magenta
    "\033[36m", // Cyan
    "\033[37m"  // Weiß
};

const char* bg_colors[] = {
    "\033[40m", // Hintergrund Schwarz
    "\033[41m", // Rot
    "\033[42m", // Grün
    "\033[43m", // Gelb
    "\033[44m", // Blau
    "\033[45m", // Magenta
    "\033[46m", // Cyan
    "\033[47m"  // Weiß
};

void farbauswahl_menu(const char* typ) {
    printf("Wähle %s:\n", typ);
    printf("0 - Schwarz\n1 - Rot\n2 - Grün\n3 - Gelb\n4 - Blau\n5 - Magenta\n6 - Cyan\n7 - Weiß\n");
    printf("Deine Auswahl: ");
}

int main() {
    int fg_index, bg_index;
    char text[MAX_TEXT];

    // Farbauswahl
    farbauswahl_menu("Textfarbe");
    scanf("%d", &fg_index);
    getchar(); // \n nach scanf entfernen

    farbauswahl_menu("Hintergrundfarbe");
    scanf("%d", &bg_index);
    getchar(); // \n nach scanf entfernen

    if (fg_index < 0 || fg_index > 7 || bg_index < 0 || bg_index > 7) {
        printf("Ungültige Farbauswahl!\n");
        return 1;
    }

    printf("Gib den Text ein, der farbig auf dem Terminal erscheinen soll:\n> ");
    fgets(text, MAX_TEXT, stdin);
    text[strcspn(text, "\n")] = '\0'; // \n entfernen

    // Farbig auf dem Terminal ausgeben
    printf("%s%s%s%s%s\n",
        BOLD,
        fg_colors[fg_index],
        bg_colors[bg_index],
        text,
        RESET);

    return 0;
}