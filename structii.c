#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int alter;
    float note;
};

int main() {
    int anzahl;
    printf("Wie viele Studierende möchtest du eingeben? ");
    scanf("%d", &anzahl);

    // 💡 Speicherplatz reservieren (malloc)
    struct Student* studenten = malloc(anzahl * sizeof(struct Student));

    if (studenten == NULL) {
        printf("Speicher konnte nicht reserviert werden!\n");
        return 1;
    }

    // 🔁 Daten einlesen
    for (int i = 0; i < anzahl; i++) {
        printf("\n--- Student %d ---\n", i + 1);

        printf("Name: ");
        scanf("%s", studenten[i].name);

        printf("Alter: ");
        scanf("%d", &studenten[i].alter);

        printf("Note: ");
        scanf("%f", &studenten[i].note);
    }

    // 📤 Daten ausgeben
    printf("\n===== STUDIERENDE =====\n");
    for (int i = 0; i < anzahl; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Name : %s\n", studenten[i].name);
        printf("Alter: %d\n", studenten[i].alter);
        printf("Note : %.2f\n", studenten[i].note);
    }

    // 🔚 Speicher freigeben
    free(studenten);

    return 0;
}