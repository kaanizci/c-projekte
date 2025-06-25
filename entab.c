#include <stdio.h>

#define TABSTOP 8 // Tab-Stopp alle 8 Spalten

int main() {
    int c, space_count = 0;
    int pos = 0; // aktuelle Spaltenposition

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            space_count++; // Leerzeichen zählen
        } else {
            if (space_count > 0) {
                // Ersetze Leerzeichen durch Tabs + Spaces
                int spaces = space_count;
                while (spaces > 0) {
                    int next_tabstop = TABSTOP - (pos % TABSTOP);
                    if (spaces >= next_tabstop) {
                        putchar('\t');
                        spaces -= next_tabstop;
                        pos += next_tabstop;
                    } else {
                        putchar(' ');
                        spaces--;
                        pos++;
                    }
                }
                space_count = 0;
            }

            // Gib das aktuelle Zeichen aus
            putchar(c);

            // Spaltenzähler aktualisieren
            if (c == '\n') {
                pos = 0; // neue Zeile beginnt
            } else if (c == '\t') {
                pos += TABSTOP - (pos % TABSTOP); // springt zum nächsten Tabstop
            } else {
                pos++;
            }
        }
    }

    return 0;
}