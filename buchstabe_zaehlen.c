#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[300];
    char buchstabe;
    int zaehler = 0;

    printf("Gib einen Text ein: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';  // Zeilenumbruch entfernen

    printf("Welchen Buchstaben willst du zählen? ");
    scanf(" %c", &buchstabe);  // das Leerzeichen vor %c ist wichtig!

    // in Kleinbuchstaben umwandeln für Vergleich
    char gesucht = tolower(buchstabe);

    for (int i = 0; text[i] != '\0'; i++) {
        if (tolower(text[i]) == gesucht) {
            zaehler++;
        }
    }

    printf("Der Buchstabe '%c' kommt %d-mal vor.\n", buchstabe, zaehler);

    return 0;
}