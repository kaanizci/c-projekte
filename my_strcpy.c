#include <stdio.h>                     // \\ Für printf zur Kontrolle

void my_strcpy(char *ziel, const char *quelle) {  // \\ Ziel: wohin kopiert wird; Quelle: was kopiert wird
    while (*quelle != '\0') {          // \\ Solange wir das Ende der Quelle nicht erreicht haben
        *ziel = *quelle;               // \\ Kopiere das Zeichen von Quelle nach Ziel
        ziel++;                        // \\ Zielzeiger eine Stelle weiter
        quelle++;                      // \\ Quellenzeiger eine Stelle weiter
    }
    *ziel = '\0';                      // \\ Endezeichen setzen (sehr wichtig!)
}

int main() {
    char quelle[] = "Programmieren ist toll";      // \\ Ursprünglicher String
    char ziel[100];                                // \\ Zielpuffer zum Kopieren

    my_strcpy(ziel, quelle);                       // \\ Kopieren durchführen
    printf("Kopiert: %s\n", ziel);                 // \\ Ergebnis anzeigen
    return 0;                                      // \\ Programm beenden
}