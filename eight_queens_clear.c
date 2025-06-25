#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 8

int x[N];

int place(int k, int i) {
    for (int j = 0; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return 0;
        }
    }
    return 1;
}

void print_solution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%s", x[i] == j ? " Q " : " . ");
        }
        printf("\n");
    }
    printf("\n");
}

void nqueen(int k) {
    for (int i = 0; i < N; i++) {
        if (place(k, i)) {
            x[k] = i;
            if (k == N - 1) {
                print_solution();
            } else {
                nqueen(k + 1);
            }
        }
    }
}

int main() {
    nqueen(0);
    return 0;
}