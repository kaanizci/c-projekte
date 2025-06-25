#include <stdio.h>

#define MAXLINE 1000  // Maximale Zeilenlänge

// Funktion zum Einlesen einer Zeile
int getline_custom(char s[], int lim);

// Funktion zum Umkehren eines Strings
void reverse(char s[]);

int main() {
    char line[MAXLINE];

    // Lese Zeile für Zeile, solange eine Zeile eingelesen werden kann
    while (getline_custom(line, MAXLINE) > 0) {
        reverse(line);                  // Kehre die Zeile um
        printf("%s", line);             // Gib sie aus
    }

    return 0;
}

// Lies eine Zeile vom Benutzer (ähnlich wie fgets)
int getline_custom(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }

    if (c == '\n') {     // Zeilenumbruch auch speichern
        s[i++] = c;
    }

    s[i] = '\0';         // Null-Terminierung des Strings
    return i;            // Länge zurückgeben
}

// Dreht den String s um
void reverse(char s[]) {
    int i = 0;
    int j;

    // Länge des Strings (ohne '\n' und '\0') ermitteln
    while (s[i] != '\0' && s[i] != '\n') {
        i++;
    }

    j = i - 1;  // Index auf das letzte echte Zeichen (nicht '\0')
    i = 0;

    // Zeichen vertauschen: Anfang mit Ende, bis zur Mitte
    char temp;
    while (i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}