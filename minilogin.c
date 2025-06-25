#include <stdio.h>
#include <string.h>

int main() {
    char richtigerBenutzer[] = "kaan";
    char richtigesPasswort[20];

    // Passwort aus Datei laden
    FILE *file = fopen("passwort.txt", "r");
    if (file != NULL) {
        fscanf(file, "%s", richtigesPasswort);
        fclose(file);
    } else {
        // Wenn Datei fehlt, Standardpasswort verwenden
        strcpy(richtigesPasswort, "1234");
    }

    char benutzerEingabe[20];
    char passwortEingabe[20];

    printf("Benutzername: ");
    scanf("%s", benutzerEingabe);

    printf("Passwort: ");
    scanf("%s", passwortEingabe);

    if (strcmp(benutzerEingabe, richtigerBenutzer) == 0 &&
        strcmp(passwortEingabe, richtigesPasswort) == 0) {
        printf("Anmeldung erfolgreich. Willkommen %s!\n", benutzerEingabe);
    } else {
        printf("Falsche Eingabe.\n");
        printf("Möchtest du dein Passwort zurücksetzen? (ja/nein): ");
        char antwort[10];
        scanf("%s", antwort);

        if (strcmp(antwort, "ja") == 0) {
            printf("Neues Passwort eingeben: ");
            scanf("%s", richtigesPasswort);

            // Neues Passwort in Datei schreiben
            file = fopen("passwort.txt", "w");
            if (file != NULL) {
                fprintf(file, "%s", richtigesPasswort);
                fclose(file);
                printf("Passwort aktualisiert und gespeichert!\n");
            } else {
                printf("Fehler beim Speichern des Passworts.\n");
            }
        } else {
            printf("Auf Wiedersehen.\n");
        }
    }

    return 0;
}