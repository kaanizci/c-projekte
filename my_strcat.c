#include <stdio.h>                     // \\ Für printf zur Ausgabe

void my_strcat(char *ziel, const char *anhang) {  // \\ Ziel = erster String, Anhang = was angehängt wird
    // Schritt 1: Zielzeiger ans Ende bringen
    while (*ziel != '\0') {            // \\ Solange Zeichen vorhanden sind (nicht '\0')
        ziel++;                        // \\ Einen Schritt weiter im Ziel
    }

    // Schritt 2: Anhang-Zeichen kopieren
    while (*anhang != '\0') {          // \\ Solange Anhang nicht zu Ende ist
        *ziel = *anhang;               // \\ Aktuelles Zeichen aus anhang ins Ziel kopieren
        ziel++;                        // \\ Zielzeiger weiterrücken
        anhang++;                      // \\ Anhangzeiger weiterrücken
    }

    *ziel = '\0';                      // \\ Am Ende String-Ende markieren
}

int main() {
    char s1[100] = "Hallo, ";          // \\ Zielstring, genug Platz für Anhang
    char s2[] = "Welt!";               // \\ Was angehängt werden soll

    my_strcat(s1, s2);                 // \\ Strings verketten
    printf("Zusammengefügt: %s\n", s1); // \\ Ergebnis anzeigen

    return 0;                          // \\ Programm beenden
}