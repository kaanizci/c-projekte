#include <stdio.h>

int main() {
    int arr[] = {123, 3222, 83, 4, 24};               // Unser Array
    int size = sizeof(arr) / sizeof(arr[0]);  // Größe des Arrays ermitteln

    // Äußere Schleife: Jede Position von links nach rechts
    for (int i = 0; i < size - 1; i++) {
        int maxIndex = i; // Wir nehmen an, das größte Element sei bei i

        // Innere Schleife: Suche das tatsächlich größte Element ab Position i
        for (int j = i + 1; j < size; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j; // Neuer größerer Wert gefunden
            }
        }

        // Tauschen, falls nötig
        if (maxIndex != i) {
            int temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
        }
    }

    // Ausgabe des sortierten Arrays
    printf("Absteigend sortiertes Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}