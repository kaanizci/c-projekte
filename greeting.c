#include <stdio.h>
#include <string.h>

int main() {
    char name[50];
    char essen[50];
    int auswahl;
    int laufend = 1;
    int ergebnis; // Neu: Ergebnis von scanf speichern

    printf("Wie heißt du?\n");
    fgets(name, sizeof(name), stdin);

    if (name[strlen(name) - 1] == '\n') {
        name[strlen(name) - 1] = '\0';
    }

    while (laufend) {
        printf("\nWas möchtest du tun?\n");
        printf("1 - Begrüßung\n");
        printf("2 - Beenden\n");
        printf("3 - Lieblingsessen nennen\n");
        printf("Bitte gib deine Wahl ein: ");

        ergebnis = scanf("%d", &auswahl);

        // Eingabepuffer aufräumen
        while (getchar() != '\n');

        if (ergebnis != 1) {
            printf("Ungültige Eingabe! Bitte gib eine Zahl ein.\n");
            continue;  // zurück zum Anfang der Schleife
        }

        if (auswahl == 1) {
            printf("Hallo, %s! Schön, dich zu sehen!\n", name);
        } else if (auswahl == 2) {
            printf("Programm wird beendet. Auf Wiedersehen, %s!\n", name);
            laufend = 0;
        } else if (auswahl == 3) {
            printf("Was ist dein Lieblingsessen?\n");
            fgets(essen, sizeof(essen), stdin);

            if (essen[strlen(essen) - 1] == '\n') {
                essen[strlen(essen) - 1] = '\0';
            }

            printf("Oh, %s klingt lecker, %s!\n", essen, name);
        } else {
            printf("Ungültige Option. Bitte wähle 1, 2 oder 3.\n");
        }
    }

    return 0;
}