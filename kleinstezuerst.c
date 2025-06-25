#include <stdio.h>

int main() {
    int arr[] = {52, 33, 83, 42, 22};         // Unser Array
    int size = sizeof(arr) / sizeof(arr[0]); // Anzahl der Elemente

    // Äußere Schleife: Gehe jedes Element durch (außer das letzte)
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i; // Merke dir: "Hier vermute ich die kleinste Zahl"

        // Innere Schleife: Suche die wirklich kleinste Zahl ab Index i
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Neuer kleiner Wert gefunden!
            }
        }

        // Wenn nötig: tausche arr[i] mit arr[minIndex]
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    // Ergebnis ausgeben
    printf("Sortiertes Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}