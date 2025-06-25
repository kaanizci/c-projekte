#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 🔄 Binär-Ausgabe-Funktion
void printBinary(long num) {
    char bin[65]; // bis zu 64 Bit
    int index = 0;

    if (num == 0) {
        printf("0");
        return;
    }

    while (num > 0) {
        bin[index++] = (num % 2) + '0';
        num /= 2;
    }

    // rückwärts ausgeben
    for (int i = index - 1; i >= 0; i--) {
        putchar(bin[i]);
    }
}

// 🎯 Hauptfunktion
int main() {
    int wahl;
    char input[100];

    printf("Zahlensystem-Umwandler\n");
    printf("----------------------\n");
    printf("1. Hexadezimal (z. B. 1A)\n");
    printf("2. Dezimal (z. B. 26)\n");
    printf("3. Binär (z. B. 11010)\n");
    printf("Wähle das Eingabesystem (1–3): ");
    scanf("%d", &wahl);

    printf("Gib die Zahl ein: ");
    scanf("%s", input);

    long dezimal;

    if (wahl == 1) {
        dezimal = strtol(input, NULL, 16); // hex
    } else if (wahl == 2) {
        dezimal = strtol(input, NULL, 10); // dez
    } else if (wahl == 3) {
        dezimal = strtol(input, NULL, 2);  // bin
    } else {
        printf("Ungültige Auswahl.\n");
        return 1;
    }

    // Ausgabe
    printf("\nUmwandlungsergebnisse:\n");
    printf("Dezimal     : %ld\n", dezimal);
    printf("Hexadezimal : %lX\n", dezimal);
    printf("Binär       : ");
    printBinary(dezimal);
    printf("\n");

    return 0;
}