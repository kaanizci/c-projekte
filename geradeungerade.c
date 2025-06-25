#include <stdio.h>

int main() {
    int x;
    printf("Geben Sie eine ganze Zahl ein: ");
    scanf("%d", &x);
 
    if (x % 2 == 0) {
        printf("Die Zahl %d ist gerade.\n", x);
    } else {
        printf("Die Zahl %d ist ungerade.\n", x);
    }
    return 0;
}