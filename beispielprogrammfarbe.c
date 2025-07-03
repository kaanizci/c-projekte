#include <stdio.h>

int main() {
    printf("\033[31mDieser Text ist rot!\033[0m\n");
    printf("\033[32mDieser Text ist grün!\033[0m\n");
    printf("\033[34mDieser Text ist blau!\033[0m\n");
    printf("Und dieser ist wieder normal.\n");
    printf("\033[1;31;47mHallo Welt!\033[0m\n");

    return 0;
}