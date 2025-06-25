#include <stdio.h>

// Eigene strlen-Funktion
int my_strlen(char *str) {
    int len = 0;
    while (*str != '\0') {
        len++;
        str++;
    }
    return len;
}

// Prüft, ob ein Zeichen ein Sonderzeichen ist
int is_special(char c) {
    char specials[] = "!@#$%&";
    for (int i = 0; specials[i] != '\0'; i++) {
        if (c == specials[i]) return 1;
    }
    return 0;
}

// Prüft, ob ein Zeichen ein Großbuchstabe ist
int is_uppercase(char c) {
    return (c >= 'A' && c <= 'Z');
}

int main() {
    char password[100];
    printf("Passwort eingeben: ");
    scanf("%s", password);

    int length = my_strlen(password);
    int has_special = 0, has_upper = 0;

    for (int i = 0; password[i] != '\0'; i++) {
        if (is_special(password[i])) has_special = 1;
        if (is_uppercase(password[i])) has_upper = 1;
    }

    if (length >= 8 && has_special && has_upper) {
        printf("✔️ Passwort akzeptiert\n");
    } else {
        printf("❌ Passwort zu schwach\n");
        if (length < 8) printf("- Mindestens 8 Zeichen nötig\n");
        if (!has_special) printf("- Sonderzeichen fehlt (!@#$%&)\n");
        if (!has_upper) printf("- Großbuchstabe fehlt\n");
    }

    return 0;
}