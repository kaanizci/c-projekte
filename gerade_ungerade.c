#include <stdio.h>

int main() {
    int zahl;

    printf("Gib eine ganze Zahl ein: ");
    scanf("%d", &zahl);

    if (zahl % 2 == 0) {
        printf("Die Zahl %d ist gerade.\n", zahl);
    } else {
        printf("Die Zahl %d ist ungerade.\n", zahl);
    }

    return 0;
}