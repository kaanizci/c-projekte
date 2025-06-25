#include <stdio.h>

int main() {
    float x;
    float result;

    // Eingabe
    printf("Gib einen Wert für x ein: ");
    scanf("%f", &x);

    // Berechnung des Polynoms
    result = 3 * x * x * x * x * x
           + 2 * x * x * x * x
           - 5 * x * x * x
           - 1 * x * x
           + 7 * x
           - 6;

    // Ausgabe
    printf("Der Wert des Polynoms ist: %.2f\n", result);

    return 0;
}