#include <stdio.h>

int main() {
    int a, b;

    // Eingabe
    printf("Gib die erste ganze Zahl ein: ");
    scanf("%d", &a);

    printf("Gib die zweite ganze Zahl ein: ");
    scanf("%d", &b);

    // Berechnungen und Ausgabe
    printf("Summe: %d\n", a + b);
    printf("Differenz: %d\n", a - b);
    printf("Produkt: %d\n", a * b);
    
    if (b != 0) {
        printf("Ganzzahldivision: %d\n", a / b);
        printf("Rest (Modulo): %d\n", a % b);
    } else {
        printf("Division durch 0 nicht möglich!\n");
    }

    return 0;
}