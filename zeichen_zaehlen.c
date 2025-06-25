#include <stdio.h>
#include <string.h>

int main() {
    char eingabe[200];

    printf("Gib einen Namen oder ein Wort ein: ");
    fgets(eingabe, sizeof(eingabe), stdin);

    // Zeilenumbruch '\n' entfernen, falls vorhanden
    eingabe[strcspn(eingabe, "\n")] = '\0';

    int laenge = strlen(eingabe);

    printf("Der eingegebene Text hat %d Zeichen.\n", laenge);

    return 0;
}