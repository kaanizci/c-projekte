#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>  // Für fmax und fmin

// Funktion zur Berechnung des Medians zweier sortierter Arrays
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Immer das kleinere Array als nums1 verwenden für effizientes Binary Search
    if (nums1Size > nums2Size) {
        int* temp = nums1;
        nums1 = nums2;
        nums2 = temp;
        int tempSize = nums1Size;
        nums1Size = nums2Size;
        nums2Size = tempSize;
    }

    int low = 0, high = nums1Size;

    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (nums1Size + nums2Size + 1) / 2 - partitionX;

        int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minX = (partitionX == nums1Size) ? INT_MAX : nums1[partitionX];

        int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minY = (partitionY == nums2Size) ? INT_MAX : nums2[partitionY];

        if (maxX <= minY && maxY <= minX) {
            // Gerade Anzahl: Mittelwert der beiden mittleren Werte
            if ((nums1Size + nums2Size) % 2 == 0) {
                return (double)(fmax(maxX, maxY) + fmin(minX, minY)) / 2.0;
            } else {
                // Ungerade Anzahl: Größere der beiden linken Werte
                return (double)fmax(maxX, maxY);
            }
        } else if (maxX > minY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }

    return -1.0; // Sollte bei gültigen Eingaben nie erreicht werden
}

int main() {
    // Testfall 1
    int nums1[] = {1, 3};
    int nums2[] = {2};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);

    double median = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
    printf("Median of the two sorted arrays is: %.1f\n", median);  // Erwartet: 2.0

    // Testfall 2
    int nums3[] = {1, 2};
    int nums4[] = {3, 4};
    nums1Size = sizeof(nums3) / sizeof(nums3[0]);
    nums2Size = sizeof(nums4) / sizeof(nums4[0]);

    median = findMedianSortedArrays(nums3, nums1Size, nums4, nums2Size);
    printf("Median of the two sorted arrays is: %.1f\n", median);  // Erwartet: 2.5

    return 0;
}