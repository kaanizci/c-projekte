#include <stdio.h>

#define MAXLINE 1000 // Maximale Anzahl an Zeichen, die wir pro Zeile speichern (inkl. '\0')

// Funktionsdeklarationen
int getline_custom(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int len;                  // Länge der aktuell gelesenen Zeile
    int max = 0;              // Länge der bisher längsten Zeile
    char line[MAXLINE];      // Temporärer Speicher für eine Eingabezeile
    char longest[MAXLINE];   // Speicher für den Anfang der längsten Zeile

    // Schleife: Solange Eingabezeilen gelesen werden können
    while ((len = getline_custom(line, MAXLINE)) > 0) {
        printf("Zeile hatte %d Zeichen\n", len); // Aktuelle Länge der Zeile ausgeben

        // Wenn die aktuelle Zeile länger als alle bisher gelesenen ist
        if (len > max) {
            max = len;              // Neue maximale Länge merken
            copy(longest, line);    // Den Teil, den wir gespeichert haben, sichern
        }
    }

    // Wenn mindestens eine Zeile gelesen wurde
    if (max > 0) {
        printf("\nDie längste Zeile hatte %d Zeichen:\n", max);
        printf("%s\n", longest); // Nur der gespeicherte Anfang wird ausgegeben
    }

    return 0;
}

// Funktion liest eine Eingabezeile zeichenweise ein und zählt dabei ALLE Zeichen
// Sie speichert jedoch nur die ersten (maxline - 1) Zeichen in das Array `s`
int getline_custom(char s[], int maxline) {
    int c, i;
    
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        // Nur die ersten maxline - 1 Zeichen im Array speichern
        if (i < maxline - 1) {
            s[i] = c;
        }
    }

    // Falls ein Zeilenumbruchzeichen gelesen wurde, evtl. auch speichern
    if (c == '\n') {
        if (i < maxline - 1) {
            s[i] = c;  // Zeilenumbruch speichern
            ++i;
        } else {
            ++i;       // Nur für die Längenzählung
        }
    }

    // Null-Terminierung des Strings (wichtig für printf und copy)
    if (i < maxline)
        s[i] = '\0';
    else
        s[maxline - 1] = '\0';

    return i; // Gibt die GESAMTE Länge der Zeile zurück (auch ungespeicherte Zeichen)
}

// Kopiert die Zeichen aus `from` nach `to`, bis das Null-Zeichen '\0' erreicht ist
void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}