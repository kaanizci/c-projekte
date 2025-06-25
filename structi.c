#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int alter;
    float note;
};

int main() {
    struct Student studenten[3];  // Ein Array mit 3 Student-Objekten

    // 👉 Feste Werte zuweisen
    strcpy(studenten[0].name, "Ali");
    studenten[0].alter = 20;
    studenten[0].note = 1.7;

    strcpy(studenten[1].name, "Merve");
    studenten[1].alter = 22;
    studenten[1].note = 2.3;

    strcpy(studenten[2].name, "Kaan");
    studenten[2].alter = 19;
    studenten[2].note = 1.3;

    // 👉 Ausgabe mit Schleife
    for (int i = 0; i < 3; i++) {
    
        printf("\n--- Student %d ---\n", i + 1);
        printf("Name : %s\n", studenten[i].name);
        printf("Alter: %d\n", studenten[i].alter);
        printf("Note : %.2f\n", studenten[i].note);
    }

    return 0;
}