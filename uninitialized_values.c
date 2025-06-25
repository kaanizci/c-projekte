#include <stdio.h>

int main() {
    int a = 1, b = 2, c = 3;
    float x = 13.290192, y = 3.09920, z = 2.71828;

    printf("Uninitialized int values:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);

    printf("\nUninitialized float values:\n");
    printf("x = %7f\n", x);
    printf("y = %7f\n", y);
    printf("z = %7f\n", z);

    return 0;
}