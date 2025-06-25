/*
=============================
🟢 Schritt 1: Pointer verstehen
=============================
*/
#include <stdio.h>

int main() {
    int zahl = 10;            // normale Variable
    int* ptr = &zahl;         // Pointer zeigt auf die Adresse von "zahl"

    printf("Wert von zahl: %d\n", zahl);       // 10
    printf("Adresse von zahl: %p\n", &zahl);   // z. B. 0x7ffee...
    printf("Wert von ptr: %p\n", ptr);         // gleiche Adresse
    printf("Wert an Adresse (mit *ptr): %d\n", *ptr); // Dereferenzierung: 10

    *ptr = 20;  // ändert den Wert an der Adresse => zahl ist jetzt 20
    printf("Neuer Wert von zahl: %d\n", zahl);
    return 0;
}