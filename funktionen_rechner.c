#include <stdio.h>

// Funktionsdeklarationen
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);

int main() {
    float x, y, ergebnis;
    int wahl;

    printf("Wähle eine Rechenart:\n");
    printf("1 - Addition\n2 - Subtraktion\n3 - Multiplikation\n4 - Division\n");
    printf("Deine Auswahl: ");
    scanf("%d", &wahl);

    printf("Gib die erste Zahl ein: ");
    scanf("%f", &x);
    printf("Gib die zweite Zahl ein: ");
    scanf("%f", &y);

    switch (wahl) {
        case 1:
            ergebnis = add(x, y);
            printf("Ergebnis: %.2f\n", ergebnis);
            break;
        case 2:
            ergebnis = subtract(x, y);
            printf("Ergebnis: %.2f\n", ergebnis);
            break;
        case 3:
            ergebnis = multiply(x, y);
            printf("Ergebnis: %.2f\n", ergebnis);
            break;
        case 4:
            if (y != 0)
                ergebnis = divide(x, y);
            else {
                printf("Fehler: Division durch 0 nicht möglich.\n");
                return 1;
            }
            printf("Ergebnis: %.2f\n", ergebnis);
            break;
        default:
            printf("Ungültige Auswahl.\n");
    }

    return 0;
}

// Funktionsdefinitionen
float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    return a / b;
}