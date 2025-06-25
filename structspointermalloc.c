
/*
================================================
🔴 Schritt 4: Structs + Pointer + malloc kombinieren
================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int alter;
};

int main() {
    struct Student* s = malloc(sizeof(struct Student));
    if (!s) return 1;

    strcpy(s->name, "Leyla");
    s->alter = 22;

    printf("Name: %s, Alter: %d\n", s->name, s->alter);
    free(s);
    return 0;
}

