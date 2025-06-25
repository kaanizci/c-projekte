#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Eine Struktur für einen einzelnen Term wie ax^n
typedef struct {
    int coeff;
    int exp;
} Term;

// Hilfsfunktion: Term aus String parsen
Term parseTerm(const char* str) {
    Term term = {0, 0}; // Standard: 0x^0
    int i = 0;
    int sign = 1;

    // Vorzeichen behandeln
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    // Koeffizient einlesen (z. B. 3 bei 3x^2 oder 5 bei 5x)
    int coeff = 0;
    int coeff_found = 0;
    while (isdigit(str[i])) {
        coeff = coeff * 10 + (str[i] - '0');
        i++;
        coeff_found = 1;
    }
    if (!coeff_found && str[i] == 'x') coeff = 1; // Sonderfall: x^n statt 1x^n

    // x verarbeiten
    if (str[i] == 'x') {
        i++;
        term.exp = 1; // default exponent = 1
        if (str[i] == '^') {
            i++;
            int exp = 0;
            int exp_sign = 1;

            // Negativer Exponent?
            if (str[i] == '-') {
                exp_sign = -1;
                i++;
            }

            while (isdigit(str[i])) {
                exp = exp * 10 + (str[i] - '0');
                i++;
            }
            term.exp = exp_sign * exp;
        }
    } else {
        // kein x -> Konstante
        term.exp = 0;
    }

    term.coeff = sign * (coeff_found ? coeff : 1);
    return term;
}

// Ableitung eines Terms
Term derive(Term t) {
    Term d;
    if (t.exp == 0) {
        d.coeff = 0;
        d.exp = 0;
    } else {
        d.coeff = t.coeff * t.exp;
        d.exp = t.exp - 1;
    }
    return d;
}

// Formatierte Ausgabe eines Terms
void formatTerm(char* buffer, Term t, int isFirst) {
    if (t.coeff == 0) return;

    char temp[50];

    // Vorzeichen: nur bei nicht erstem Term
    if (!isFirst) {
        if (t.coeff > 0)
            sprintf(temp, "+");
        else
            sprintf(temp, "-");
        strcat(buffer, temp);
    } else {
        if (t.coeff < 0)
            sprintf(temp, "-");
        else
            sprintf(temp, "");
        strcat(buffer, temp);
    }

    int absCoeff = abs(t.coeff);

    if (t.exp == 0) {
        sprintf(temp, "%d", absCoeff);
    } else if (t.exp == 1) {
        if (absCoeff == 1)
            sprintf(temp, "x");
        else
            sprintf(temp, "%dx", absCoeff);
    } else {
        if (absCoeff == 1)
            sprintf(temp, "x^%d", t.exp);
        else
            sprintf(temp, "%dx^%d", absCoeff, t.exp);
    }

    strcat(buffer, temp);
}

int main() {
    char input[256];
    printf("Gib ein Polynom ein (z. B. 3x^2+2x-5): ");
    scanf("%255s", input);

    // Zerlege die Eingabe in Terme
    char* token = strtok(input, "+-");
    char ops[256] = {0}; // um Vorzeichen zu speichern
    int op_index = 0;
    if (input[0] != '+' && input[0] != '-') {
        ops[op_index++] = '+';
    }

    for (int i = 1; input[i]; i++) {
        if (input[i] == '+' || input[i] == '-') {
            ops[op_index++] = input[i];
        }
    }

    Term terms[50];
    int count = 0;

    while (token != NULL) {
        char signed_token[64] = {0};
        signed_token[0] = ops[count];
        strcat(signed_token, token);
        terms[count] = parseTerm(signed_token);
        count++;
        token = strtok(NULL, "+-");
    }

    // Alle Terme ableiten
    Term derived[50];
    for (int i = 0; i < count; i++) {
        derived[i] = derive(terms[i]);
    }

    // Ausgabe
    printf("Ableitung: ");
    char result[256] = "";
    int first = 1;
    for (int i = 0; i < count; i++) {
        char part[64] = "";
        formatTerm(part, derived[i], first);
        if (strlen(part) > 0) {
            strcat(result, part);
            first = 0;
        }
    }

    if (strlen(result) == 0)
        printf("0\n");
    else
        printf("%s\n", result);

    return 0;
}