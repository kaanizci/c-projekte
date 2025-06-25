/*
=============================
🔵 Schritt 3: Structs Basics
=============================
*/
#include <stdio.h>
#include <string.h>

struct Student {
    char name[20];
    int alter;
};

int main() {
    struct Student s1;
    strcpy(s1.name, "Ali");
    s1.alter = 21;

    printf("Name: %s, Alter: %d\n", s1.name, s1.alter);
    return 0;
}
