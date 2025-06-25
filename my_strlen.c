#include <stdio.h>                   // \\ Für printf, um das Ergebnis auszugeben

int my_strlen(char *str) {          // \\ Funktion erwartet einen Zeiger auf einen String (char*)
    int length = 0;                 // \\ Zähler wird auf 0 gesetzt

    while (*str != '\0') {          // \\ Solange das aktuelle Zeichen NICHT das Ende ist ('\0')
        length++;                   // \\ Zähler um 1 erhöhen
        str++;                      // \\ Zeiger auf das nächste Zeichen bewegen
    }

    return length;                  // \\ Am Ende die gezählte Länge zurückgeben
}

int main() {
    char text[] = "Hallo Welt";     // \\ Beispiel-String zum Testen
    int len = my_strlen(text);      // \\ Funktion aufrufen, Länge berechnen
    printf("Länge: %d\n", len);     // \\ Länge ausgeben
    return 0;                       // \\ Programm normal beenden
}