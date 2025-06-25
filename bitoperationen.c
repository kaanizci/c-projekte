#include <stdio.h>

// Hilfsfunktion zur binären Darstellung
void printBinary(unsigned int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) printf(" "); // für bessere Lesbarkeit
    }
    printf("\n");
}

int main() {
    unsigned int a, b;
    int wahl;

    printf("🔢 Bit-Operations-Rechner\n");
    printf("Zahl A eingeben: ");
    scanf("%u", &a);

    printf("Zahl B eingeben: ");
    scanf("%u", &b);

    printf("\nOperation wählen:\n");
    printf("1. A & B (AND)\n");
    printf("2. A | B (OR)\n");
    printf("3. A ^ B (XOR)\n");
    printf("4. ~A (NOT)\n");
    printf("5. A << n (Shift Left)\n");
    printf("6. A >> n (Shift Right)\n");
    printf("Deine Wahl: ");
    scanf("%d", &wahl);

    unsigned int ergebnis;
    int shift;

    switch (wahl) {
        case 1:
            ergebnis = a & b;
            printf("\nA & B = %u\n", ergebnis);
            printBinary(ergebnis);
            break;
        case 2:
            ergebnis = a | b;
            printf("\nA | B = %u\n", ergebnis);
            printBinary(ergebnis);
            break;
        case 3:
            ergebnis = a ^ b;
            printf("\nA ^ B = %u\n", ergebnis);
            printBinary(ergebnis);
            break;
        case 4:
            ergebnis = ~a;
            printf("\n~A = %u\n", ergebnis);
            printBinary(ergebnis);
            break;
        case 5:
            printf("Wie viele Bits nach links verschieben? ");
            scanf("%d", &shift);
            ergebnis = a << shift;
            printf("\nA << %d = %u\n", shift, ergebnis);
            printBinary(ergebnis);
            break;
        case 6:
            printf("Wie viele Bits nach rechts verschieben? ");
            scanf("%d", &shift);
            ergebnis = a >> shift;
            printf("\nA >> %d = %u\n", shift, ergebnis);
            printBinary(ergebnis);
            break;
        default:
            printf("Ungültige Wahl!\n");
    }

    return 0;
}