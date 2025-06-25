#include <stdio.h>

// Bitweises UND
int AND(int a, int b) {
    return a & b;
}

// Bitweises ODER
int OR(int a, int b) {
    return a | b;
}

// Bitweises NICHT (für 1-Bit-Logik negieren wir das Bit & maskieren)
int NOT(int a) {
    return ~a & 1;
}

// Bitweises XOR
int XOR(int a, int b) {
    return a ^ b;
}

int main() {
    printf("A B | AND OR XOR\n");
    printf("--------------\n");
    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            printf("%d %d |  %d   %d   %d\n", 
                a, b, AND(a, b), OR(a, b), XOR(a, b));
        }
    }
    return 0;
}