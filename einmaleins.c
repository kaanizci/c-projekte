#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("   |");
    for (int i = 1; i <= 10; i++) {
        printf("%4d", i);
    }
    printf("\n---+-----------------------------------------\n");

    for (int i = 1; i <= 10; i++) {
        printf("%2d |", i);  // linke Spalte
        for (int j = 1; j <= 10; j++) {
            printf("%4d", i * j);  // Zelle = i * j
        }
        printf("\n");
    }

   
}