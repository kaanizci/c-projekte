#include <stdio.h>

int main() {
    int zahl;

    // Eingabeaufforderung für den Benutzer
    printf("Gib eine ganze Zahl ein: ");
    scanf("%d", &zahl);  // Benutzerinput lesen

    // Multiplikationstabelle mit einer Schleife ausgeben
    printf("Multiplikationstabelle für %d:\n", zahl);
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", zahl, i, zahl * i);
    }

    return 0;  // Erfolgreiches Beenden des Programms
}