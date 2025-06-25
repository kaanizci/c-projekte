#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000  // maximale Eingabezeilenlänge

// Funktion zum Einlesen einer Zeile
int get_line(char line[], int max) {
    int c, i = 0;
    while (i < max - 1 && (c = getchar()) != EOF && c != '\n')
        line[i++] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}

// Funktion zum Umbruch einer langen Zeile
void fold_line(char line[], int len, int fold_width) {
    int col = 0;           // aktuelle Spalte
    int last_space = -1;   // Position des letzten Leerzeichens

    for (int i = 0; i < len; i++) {
        char c = line[i];
        putchar(c);
        col++;

        if (c == ' ' || c == '\t') {
            last_space = i;
        }

        if (col >= fold_width) {  // ✅ jetzt korrekt!
            if (last_space >= 0) {
                putchar('\n');        // Zeilenumbruch an letzter Leerstelle
                i = last_space;       // zurückspringen, um danach weiterzumachen
                last_space = -1;
                col = 0;
            } else {
                // kein Leerzeichen gefunden → harter Umbruch
                putchar('\n');
                col = 0;
            }
        }

        if (c == '\n') {
            col = 0;
            last_space = -1;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Benutzung: %s <Spaltenbreite>\n", argv[0]);
        return 1;
    }

    int fold_width = atoi(argv[1]);  // Wert aus Argument

    char line[MAXLINE];
    int len;

    while ((len = get_line(line, MAXLINE)) > 0) {
        fold_line(line, len, fold_width);
    }

    return 0;
}