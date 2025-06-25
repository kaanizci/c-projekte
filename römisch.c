#include <stdio.h>

// 🔢 Funktion zur Umwandlung eines römischen Zeichens in einen Zahlenwert
int value(char c) {
    switch(c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

// 🧠 Funktion zur Umwandlung einer ganzen römischen Zahl in eine int-Zahl
int romanToInt(char *s) {
    int total = 0;
    int i = 0;

    while (s[i] != '\0') {
        int current = value(s[i]);
        int next = value(s[i + 1]);

        if (current < next) {
            total += (next - current);
            i += 2;  // Zwei Buchstaben überspringen
        } else {
            total += current;
            i++;
        }
    }

    return total;
}

// 🎯 Hauptfunktion – liest Benutzereingabe ein und zeigt das Ergebnis
int main() {
    char roman[20];  // Platz für bis zu 19 Zeichen + \0

    printf("Gib eine römische Zahl ein (z.B. MCMXCIV): ");
    scanf("%s", roman);

    int result = romanToInt(roman);
    printf("Der Zahlenwert ist: %d\n", result);

    return 0;
}