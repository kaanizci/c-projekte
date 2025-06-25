#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LEN 100 // Maximale Länge pro Wort

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";

    int minLength = strlen(strs[0]);
    for (int i = 1; i < strsSize; i++) {
        int len = strlen(strs[i]);
        if (len < minLength) {
            minLength = len;
        }
    }

    char* prefix = (char*)malloc((minLength + 1) * sizeof(char));
    if (!prefix) return NULL;

    for (int i = 0; i < minLength; i++) {
        char currentChar = tolower(strs[0][i]);
        for (int j = 1; j < strsSize; j++) {
            if (tolower(strs[j][i]) != currentChar) {
                prefix[i] = '\0';
                return prefix;
            }
        }
        prefix[i] = currentChar;
    }
    prefix[minLength] = '\0';
    return prefix;
}

int main() {
    int strsSize;
    printf("Wie viele Wörter möchtest du eingeben? ");
    scanf("%d", &strsSize);

    getchar(); // Puffer leeren (für '\n' nach scanf)

    // Speicher für das Array von Strings reservieren
    char** strs = (char**)malloc(strsSize * sizeof(char*));
    if (!strs) {
        printf("Fehler bei der Speicherreservierung für das Array.\n");
        return 1;
    }

    // Speicher für jedes einzelne Wort reservieren + Eingabe
    for (int i = 0; i < strsSize; i++) {
        strs[i] = (char*)malloc(MAX_LEN * sizeof(char));
        if (!strs[i]) {
            printf("Fehler bei der Speicherreservierung für Wort %d.\n", i);
            return 1;
        }
        printf("Wort %d eingeben: ", i + 1);
        fgets(strs[i], MAX_LEN, stdin);
        strs[i][strcspn(strs[i], "\n")] = '\0'; // \n entfernen
    }

    char* prefix = longestCommonPrefix(strs, strsSize);
    if (prefix) {
        printf("\nLängstes gemeinsames Präfix: %s\n", prefix);
        free(prefix);
    } else {
        printf("Kein gemeinsames Präfix gefunden.\n");
    }

    // Speicher freigeben
    for (int i = 0; i < strsSize; i++) {
        free(strs[i]);
    }
    free(strs);

    return 0;
}