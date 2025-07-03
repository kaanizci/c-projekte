#include <stdio.h>

#define MAX 100

int main() {
    int i = 0;
    int c;
    char s[MAX];

    while (i < MAX - 1) {       // Erste Bedingung
        c = getchar();          // Zeichen einlesen

        if (c == '\n')          // Zweite Bedingung prüfen
            break;
        if (c == EOF)           // Dritte Bedingung prüfen
            break;

        s[i] = c;
        ++i;
    }

    s[i] = '\0';  // Null-Terminierung des Strings

    printf("Eingabe: %s\n", s);
    return 0;
}