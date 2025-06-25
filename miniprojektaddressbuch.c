

/*
========================================
🛠 Schritt 5: Miniprojekt – Adressbuch
========================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Kontakt {
    char name[50];
    char telefon[20];
};

int main() {
    int anzahl;
    printf("Wie viele Kontakte? ");
    scanf("%d", &anzahl);
    getchar(); // Eingabepuffer leeren

    struct Kontakt* liste = malloc(anzahl * sizeof(struct Kontakt));

    for (int i = 0; i < anzahl; i++) {
        printf("\nKontakt %d\n", i + 1);
        printf("Name: ");
        fgets(liste[i].name, 50, stdin);
        liste[i].name[strcspn(liste[i].name, "\n")] = 0; // \n entfernen

        printf("Telefon: ");
        fgets(liste[i].telefon, 20, stdin);
        liste[i].telefon[strcspn(liste[i].telefon, "\n")] = 0;
    }

    printf("\n--- Adressbuch ---\n");
    for (int i = 0; i < anzahl; i++) {
        printf("%s : %s\n", liste[i].name, liste[i].telefon);
    }

    free(liste);
    return 0;
}