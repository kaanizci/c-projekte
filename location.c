#include <stdio.h>
#include <string.h>

int any(char s1[], char s2[]) {
    for (int i = 0; s1[i] != '\0'; i++) {
        for (int j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                return i; // erste Fundstelle
            }
        }
    }
    return -1; // kein gemeinsames Zeichen
}

int main() {
    char s1[100];
    char s2[100];

    printf("Gib den ersten String ein: ");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = '\0';  // Newline entfernen

    printf("Gib den zweiten String ein: ");
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = '\0';  // Newline entfernen

    int result = any(s1, s2);

    if (result != -1)
        printf("Erstes gemeinsames Zeichen: '%c' an Position: %d\n", s1[result], result);
    else
        printf("Kein gemeinsames Zeichen gefunden.\n");

    return 0;
}