#include <stdio.h>

#define TABSTOP 8  // Tabweite, also z. B. alle 8 Spalten gibt's einen Tabstop

int main() {
    int c;           // Eingelesenes Zeichen
    int pos = 0;     // Aktuelle Spaltenposition (0-basiert)

    // Zeichen für Zeichen einlesen
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            // Berechne, wie viele Leerzeichen zum nächsten Tabstop fehlen
            int spaces = TABSTOP - (pos % TABSTOP);
            for (int i = 0; i < spaces; i++) {
                putchar(' ');
                pos++;  // Spaltenposition erhöhen
            }
        } else if (c == '\n') {
            putchar(c);
            pos = 0;  // Neue Zeile → Spaltenposition zurücksetzen
        } else {
            putchar(c);
            pos++;  // Normales Zeichen → Spalte erhöhen
        }
    }

    return 0;
}