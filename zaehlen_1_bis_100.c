#include <stdio.h>

int main() {
    int start;

    printf("Gib eine Startzahl ein (kleiner oder gleich 100): ");
    scanf("%d", &start);

    if (start > 100) {
        printf("Die Zahl ist größer als 100. Nichts zu zählen.\n");
    } else {
      for (int i = start; i <= 100; i++) {
        printf("%d\n", i);
    }
}
    return 0;
}