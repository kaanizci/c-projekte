#include <stdio.h>

int main() {
    double x, y;

    printf("Gib die erste Kommazahl ein: ");
    scanf("%lf", &x);  // Beachte: %lf für double

    printf("Gib die zweite Kommazahl ein: ");
    scanf("%lf", &y);

    printf("Summe: %.7f\n", x + y);
    printf("Differenz: %.7f\n", x - y);
    printf("Produkt: %.7f\n", x * y);

    if (y != 0.0) {
        printf("Division: %.7f\n", x / y);
    } else {
        printf("Division durch 0 nicht möglich!\n");
    }

    return 0;
}