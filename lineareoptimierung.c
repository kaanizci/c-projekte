#include <stdio.h>

int main() {
    int maxZ = 0;
    int bestX = 0, bestY = 0;

    for (int x = 0; x <= 100; x++) {
        for (int y = 0; y <= 100; y++) {

            // Nebenbedingungen prüfen
            if ((x + 2 * y <= 14) && (3 * x - y <= 18)) {

                int z = 3 * x + 2 * y; // Zielfunktion

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