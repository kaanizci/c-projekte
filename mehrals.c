#include <stdio.h>   // Für printf, getchar usw.
#define MAXLINE 1000 // Maximale Länge einer Zeile, die wir einlesen können

// Funktion, um eine Zeile einzulesen und ihre Länge zu liefern
int getline_custom(char line[], int maxline);

int main() {
    char line[MAXLINE]; // Puffer für die aktuelle Zeile
    int len;            // Länge der aktuellen Zeile

    // 📥 Schleife zum Einlesen jeder Zeile
    while ((len = getline_custom(line, MAXLINE)) > 0) {
        // 🔍 Nur Zeilen > 80 Zeichen werden ausgegeben
        if (len > 80) {
            printf("Zeile mit %d Zeichen:\n", len);
            printf("%s", line); // 🖨️ Zeile ausgeben
        }
    }

    return 0;
}

// 📦 Funktion zum Einlesen einer einzelnen Zeile
int getline_custom(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {    // Wenn Zeile mit Newline endet, einfügen
        s[i] = c;
        ++i;
    }

    s[i] = '\0';        // String terminieren
    return i;           // Zurückgeben der tatsächlichen Länge
}