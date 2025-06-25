#include <stdio.h>

#define MAXLINE 1000  // Maximale Eingabezeilenlänge

// Liest eine Zeile ein
int getline_custom(char line[], int limit);

// Entfernt Leerzeichen und Tabs am Ende der Zeile
int trim_trailing_whitespace(char line[]);

int main() {
    char line[MAXLINE];

    while (getline_custom(line, MAXLINE) > 0) {
        // Kürzt Zeile am Ende
        int trimmed_len = trim_trailing_whitespace(line);

        // Wenn die Zeile nach dem Kürzen nicht leer ist, gib sie aus
        if (trimmed_len > 0) {
            printf("%s\n", line);
        }
    }

    return 0;
}

// Liest eine Zeile in das Array ein, inklusive '\n', aber endet mit '\0'
int getline_custom(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i++] = c;  // Zeilenumbruch mitnehmen
    }

    s[i] = '\0'; // Stringende markieren
    return i;    // Zurückgegebene Zeichenanzahl (inkl. \n)
}

// Entfernt Leerzeichen und Tabs am Ende der Zeile
int trim_trailing_whitespace(char s[]) {
    int i = 0;

    // Finde das Ende der Zeichenkette (vor '\0')
    while (s[i] != '\0') {
        ++i;
    }

    // Rückwärts durchlaufen und Tabs/Spaces entfernen
    while (i > 0 && (s[i - 1] == ' ' || s[i - 1] == '\t' || s[i - 1] == '\n')) {
        --i;
    }

    s[i] = '\0'; // Neues String-Ende setzen

    return i; // Neue Länge der Zeile (nach Kürzen)
}