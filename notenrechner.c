#include <stdio.h>

int main() {
    int punkte;

    printf("Gib deine Punktzahl ein (0–100): ");
    scanf("%d", &punkte);

    if (punkte >= 90 && punkte <= 100) {
        printf("Note: 1 (sehr gut)\n");
    } else if (punkte >= 80 && punkte < 90) {
        printf("Note: 2 (gut)\n");
    } else if (punkte >= 65 && punkte < 80) {
        printf("Note: 3 (befriedigend)\n");
    } else if (punkte >= 50 && punkte < 65) {
        printf("Note: 4 (ausreichend)\n");
    } else if (punkte >= 30 && punkte < 50) {
        printf("Note: 5 (mangelhaft)\n");
    } else if (punkte >= 0 && punkte < 30) {
        printf("Note: 6 (ungenügend)\n");
    } else {
        printf("Ungültige Eingabe! Bitte gib einen Wert zwischen 0 und 100 ein.\n");
    }

    return 0;
}