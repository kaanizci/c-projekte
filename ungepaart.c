#include <stdio.h>

int main() {
    int c;
    int round = 0, curly = 0, square = 0;
    int in_single_quote = 0, in_double_quote = 0, in_comment = 0;
    int last = 0;

    while ((c = getchar()) != EOF) {
        if (in_comment) {
            if (last == '*' && c == '/') {
                in_comment = 0;
                c = 0;  // Kommentarende erkannt
            }
        } else if (in_single_quote) {
            if (c == '\'' && last != '\\') {
                in_single_quote = 0;
            }
        } else if (in_double_quote) {
            if (c == '"' && last != '\\') {
                in_double_quote = 0;
            }
        } else {
            if (last == '/' && c == '*') {
                in_comment = 1;
            } else if (c == '\'') {
                in_single_quote = 1;
            } else if (c == '"') {
                in_double_quote = 1;
            } else if (c == '(') {
                round++;
            } else if (c == ')') {
                round--;
            } else if (c == '{') {
                curly++;
            } else if (c == '}') {
                curly--;
            } else if (c == '[') {
                square++;
            } else if (c == ']') {
                square--;
            }
        }
        last = c;
    }

    if (round != 0) printf("Unmatched parentheses: %d\n", round);
    if (curly != 0) printf("Unmatched curly braces: %d\n", curly);
    if (square != 0) printf("Unmatched square brackets: %d\n", square);
    if (in_comment) printf("Unclosed comment!\n");
    if (in_single_quote) printf("Unclosed single quote!\n");
    if (in_double_quote) printf("Unclosed double quote!\n");

    if (round == 0 && curly == 0 && square == 0 &&
        !in_comment && !in_single_quote && !in_double_quote) {
        printf("✅ Keine Syntaxfehler gefunden.\n");
    }

    return 0;
}