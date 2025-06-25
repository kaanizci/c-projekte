#include <stdio.h>

int main() {
    int anzahl;
    printf("Wie viele Noten möchtest du eingeben? ");
    scanf("%d", &anzahl);

    if (anzahl <= 0) {
        printf("Ungültige Anzahl.\n");
        return 1;
    }

    double noten[anzahl];

    for (int i = 0; i < anzahl; i++) {
        printf("Note %d: ", i + 1);
        scanf("%lf", &noten[i]);
    }

    double min = noten[0];
    double max = noten[0];

    for (int i = 1; i < anzahl; i++) {
        if (noten[i] < min) {
            min = noten[i];
        }
        if (noten[i] > max) {
            max = noten[i];
        }
    }

    printf("\nBeste Note: %.9g\n", min);
    printf("Schlechteste Note: %.9g\n", max);

    return 0;
}