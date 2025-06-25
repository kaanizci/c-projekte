#include <stdio.h>    // für printf, scanf
#include <string.h>   // für strcpy (String kopieren)

// 👉 Wir erstellen unseren eigenen Datentyp namens "Student"
struct Student {
    char name[50];     // ein Text (String) für den Namen – max. 49 Buchstaben + \0
    int alter;         // ein Integer für das Alter
    float note;        // eine Kommazahl für die Note
};

int main() {
    // 👉 Wir erstellen eine Variable vom Typ "struct Student"
    struct Student s1;

    // 👉 Benutzer gibt Daten ein
    printf("Gib den Namen des Studenten ein: ");
    scanf("%49s", s1.name);  // max. 49 Zeichen lesen

    printf("Gib das Alter ein: ");
    scanf("%d", &s1.alter);  // & ist nötig, um die Adresse zu übergeben

    printf("Gib die Note ein: ");
    scanf("%f", &s1.note);

    // 👉 Ausgabe
    printf("\n--- Studentendaten ---\n");
    printf("Name : %s\n", s1.name);
    printf("Alter: %d\n", s1.alter);
    printf("Note : %.2f\n", s1.note);

    return 0;
}