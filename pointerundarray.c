/*
======================================
🟡 Schritt 2: Pointer und Arrays
======================================
*/
#include <stdio.h>

int main() {
    int arr[3] = {10, 20, 30};
    int* p = arr;  // Zeigt auf arr[0]

    printf("arr[0] = %d, *(p+0) = %d\n", arr[0], *(p+0));
    printf("arr[1] = %d, *(p+1) = %d\n", arr[1], *(p+1));
    printf("arr[2] = %d, *(p+2) = %d\n", arr[2], *(p+2));
    return 0;
}

