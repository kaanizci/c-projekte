#include <stdio.h>
#include <stdlib.h>

#define TABSTOP 8

// Moduswahl-Funktion
void print_menu() {
    printf("Wähle den Modus:\n");
    printf("1 - detab (Tabs → Leerzeichen)\n");
    printf("2 - entab (Leerzeichen → Tabs)\n");
    printf("Deine Auswahl: ");
}

// Funktion: Tabs in Leerzeichen (detab)
void detab() {
    int c, pos = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int spaces = TABSTOP - (pos % TABSTOP);
            for (int i = 0; i < spaces; i++) {
                putchar(' ');
                pos++;
            }
        } else {
            putchar(c);
            if (c == '\n') {
                pos = 0;
            } else {
                pos++;
            }
        }
    }
}

// Funktion: Leerzeichen in Tabs (entab)
void entab() {
    int c, space_count = 0, pos = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            space_count++;
        } else {
            if (space_count > 0) {
                int spaces = space_count;
                while (spaces > 0) {
                    int next_tabstop = TABSTOP - (pos % TABSTOP);
                    if (spaces >= next_tabstop) {
                        putchar('\t');
                        spaces -= next_tabstop;
                        pos += next_tabstop;
                    } else {
                        putchar(' ');
                        spaces--;
                        pos++;
                    }
                }
                space_count = 0;
            }

            putchar(c);
            if (c == '\n') {
                pos = 0;
            } else if (c == '\t') {
                pos += TABSTOP - (pos % TABSTOP);
            } else {
                pos++;
            }
        }
    }
}

// Hauptfunktion
int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Verwendung: %s <Modus>\n1 = detab, 2 = entab\n", argv[0]);
        return 1;
    }

    int mode = atoi(argv[1]);

    if (mode == 1) {
        detab();
    } else if (mode == 2) {
        entab();
    } else {
        fprintf(stderr, "Ungültiger Modus. Wähle 1 (detab) oder 2 (entab).\n");
        return 1;
    }

    return 0;
}