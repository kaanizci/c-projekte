#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char eintrag[500];

    printf("Was möchtest du heute ins Tagebuch schreiben?\n> ");
    fgets(eintrag, sizeof(eintrag), stdin); // ganze Zeile einlesen

    // Aktuelles Datum und Uhrzeit ermitteln
    time_t jetzt = time(NULL);
    struct tm *zeitinfo = localtime(&jetzt);

    // Datei im Anhangsmodus öffnen (a = append)
    FILE *datei = fopen("tagebuch.txt", "a");
    if (datei == NULL) {
        printf("Fehler beim Öffnen der Datei!\n");
        return 1;
    }

    // Datum/Uhrzeit + Eintrag speichern
    fprintf(datei, "[%02d.%02d.%04d %02d:%02d] %s\n",
        zeitinfo->tm_mday,
        zeitinfo->tm_mon + 1,
        zeitinfo->tm_year + 1900,
        zeitinfo->tm_hour,
        zeitinfo->tm_min,
        eintrag
    );

    fclose(datei);
    printf("Eintrag gespeichert!\n");

    return 0;
}