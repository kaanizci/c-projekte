#include <stdio.h>
#include <string.h>

int main() {
    char name1[100];
    char name2[100];

    printf("Gib den ersten Namen ein: ");
    scanf("%99s", name1);  // %99s um Pufferüberlauf zu vermeiden

    printf("Gib den zweiten Namen ein: ");
    scanf("%99s", name2);  // %99s um Pufferüberlauf zu vermeiden
    // Vergleiche die beiden Namen
    if (strcmp(name1, name2) == 0) {
        printf("Die Namen sind gleich.\n");
    } else {
        printf("Die Namen sind unterschiedlich.\n");
    }      
    return 0;
}   