#include <stdio.h>

void squeeze(char s1[], char s2[]) {
    int i, j, k;
    int match;

    for (i = j = 0; s1[i] != '\0'; i++) {
        match = 0; // Annahme: kein Treffer

        // Prüfe: kommt s1[i] in s2 vor?
        for (k = 0; s2[k] != '\0'; k++) {
            if (s1[i] == s2[k]) {
                match = 1; // Treffer
                break;
            }
        }

        if (!match) {
            s1[j++] = s1[i]; // Nur behalten, wenn NICHT in s2
        }
    }

    s1[j] = '\0'; // String sauber abschließen
}