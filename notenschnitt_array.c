#include <stdio.h>
#include <string.h>

#define MAX_FAECHER 100
#define MAX_NAME_LEN 50

int main() {
    int anzahl;

    printf("Wie viele Fächer möchtest du eingeben? ");
    scanf("%d", &anzahl);

    if (anzahl <= 0 || anzahl > MAX_FAECHER) {
        printf("Ungültige Anzahl von Fächern.\n");
        return 1;
    }
    char faecher[MAX_FAECHER][MAX_NAME_LEN];
    double noten[MAX_FAECHER];
    int gewichtungen[MAX_FAECHER];
    double gewichtete_summe = 0.0;
    int gesamtgewicht = 0;

    for (int i = 0; i < anzahl; i++) {
        printf("Fach %d Name: ", i + 1);
        scanf(" %[^\n]", faecher[i]); 

        printf("Note für %s: ", faecher[i]);
        scanf("%lf", &noten[i]);

        printf("Gewichtung für %s: (z. B. 1 = einfach, 2 = doppelt): ", faecher[i]);
        scanf("%d", &gewichtungen[i]);

        gewichtete_summe += noten[i] * gewichtungen[i];
        gesamtgewicht += gewichtungen[i];
    }

    double durchschnitt = gewichtete_summe / gesamtgewicht;

    printf("\nGewichteter Durchschnitt: %.9g\n", durchschnitt);

    // Ergebnis in Datei schreiben
    FILE *datei = fopen("noten_ergebnis.txt", "w");
    if (datei == NULL) {
        printf("Fehler beim Erstellen der Datei.\n");
        return 1;
    }

    fprintf(datei, "Fächer & Noten:\n");
    for (int i = 0; i < anzahl; i++) {
        fprintf(datei, "%s: Note = %.9g, Gewichtung = %d\n", faecher[i], noten[i], gewichtungen[i]);
    }
    fprintf(datei, "\nGewichteter Notendurchschnitt: %.9g\n", durchschnitt);
    fclose(datei);

    printf("Ergebnis wurde in 'noten_ergebnis.txt' gespeichert.\n");

    return 0;
}