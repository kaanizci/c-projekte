#include <stdio.h>

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {            // Äußere Schleife
        for (int j = 0; j < size - i - 1; j++) {    // Innere Schleife
            if (arr[j] > arr[j + 1]) {              // Wenn Elemente vertauscht werden müssen
                int temp = arr[j];                  // Zwischenspeicher
                arr[j] = arr[j + 1];                // Vertauschen
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {6, 323, 225, 12, 2, 11, 92};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Ursprüngliches Array:\n");
    printArray(data, size);

    bubbleSort(data, size);

    printf("Sortiertes Array mit Bubble Sort:\n");
    printArray(data, size);

    return 0;
}