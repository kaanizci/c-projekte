#include <stdio.h>
#include <math.h>  // für sqrt()

// Funktionsdeklarationen
double quadrat(double x);
double wurzel(double x);

int main() {
    int wahl;
    double zahl, ergebnis;

    printf("Was möchtest du berechnen?\n");
    printf("1 - Quadrat\n");
    printf("2 - Wurzel\n");
    printf("Deine Auswahl: ");
    scanf("%d", &wahl);

    printf("Gib eine Zahl ein: ");
    scanf("%lf", &zahl);  // %lf für double

    if (wahl == 1) {
        ergebnis = quadrat(zahl);
        printf("Quadrat von %.9g ist %.9g\n", zahl, ergebnis);
    } else if (wahl == 2) {
        if (zahl < 0) {
            printf("Fehler: Keine Wurzel aus negativen Zahlen möglich.\n");
            return 1;
        } else {
            ergebnis = wurzel(zahl);
            printf("Wurzel von %.9g ist %.9g\n", zahl, ergebnis);
        }
    } else {
        printf("Ungültige Auswahl.\n");
    }

    return 0;
}

// Funktionsdefinitionen
double quadrat(double x) {
    return x * x;
}

double wurzel(double x) {
    return sqrt(x);
}