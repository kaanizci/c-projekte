#include <stdio.h>

int main() {
    int a1, b1, c1;
    int a2, b2, c2;
    int p, q;

    printf("Zielfunktion Z = p * x + q * y\n");
    printf("Gib p und q ein: ");
    scanf("%d %d", &p, &q);

    printf("Gib die 1. Nebenbedingung in der Form a1 * x + b1 * y <= c1 ein:\n");
    scanf("%d %d %d", &a1, &b1, &c1);

    printf("Gib die 2. Nebenbedingung in der Form a2 * x + b2 * y <= c2 ein:\n");
    scanf("%d %d %d", &a2, &b2, &c2);

    int maxZ = 0;
    int bestX = 0, bestY = 0;

    for (int x = 0; x <= 100; x++) {
        for (int y = 0; y <= 100; y++) {
            if ((a1 * x + b1 * y <= c1) &&
                (a2 * x + b2 * y <= c2)) {

                int z = p * x + q * y;
                if (z > maxZ) {
                    maxZ = z;
                    bestX = x;
                    bestY = y;
                }
            }
        }
    }

    printf("Maximales Z = %d bei x = %d, y = %d\n", maxZ, bestX, bestY);
    return 0;
}