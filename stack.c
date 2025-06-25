#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur für den Stack-Knoten
typedef struct Node {
    char data[100];        // Beliebige Zeichenkette
    struct Node* next;     // Zeiger auf das nächste Element
} Node;

Node* top = NULL;  // Zeiger auf den obersten Stack-Knoten

// Funktion zum Pushen (Hinzufügen) eines Elements
void push(char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Speicherfehler beim Push!\n");
        return;
    }
    strcpy(newNode->data, value);
    newNode->next = top;
    top = newNode;
}

// Funktion zum Poppen (Entfernen) des obersten Elements
void pop() {
    if (top == NULL) {
        printf("Stack ist leer!\n");
        return;
    }
    Node* temp = top;
    top = top->next;
    free(temp);
    printf("Element entfernt.\n");
}

// Funktion zum Anzeigen aller Stack-Elemente
void display() {
    Node* current = top;
    printf("Aktueller Stack:\n");
    while (current != NULL) {
        printf("-> %s\n", current->data);
        current = current->next;
    }
}

// Funktion zum Speichern in Datei
void saveStackToFile(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Fehler beim Öffnen der Datei.\n");
        return;
    }

    Node* current = top;
    while (current != NULL) {
        fprintf(file, "%s\n", current->data);
        current = current->next;
    }

    fclose(file);
    printf("Stack wurde gespeichert in %s\n", filename);
}

// Funktion zum Laden aus Datei
void loadStackFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) return; // Datei existiert nicht – kein Problem

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0'; // Zeilenumbruch entfernen
        push(line);
    }

    fclose(file);
}

int main() {
    const char* filename = "stackdata.txt";
    loadStackFromFile(filename); // Stack beim Start laden

    int choice;
    char value[100];

    do {
        printf("\n1. Push\n2. Pop\n3. Anzeigen\n4. Beenden\n> ");
        scanf("%d", &choice);
        getchar(); // Eingabepuffer leeren

        switch (choice) {
            case 1:
                printf("Wert eingeben: ");
                fgets(value, sizeof(value), stdin);
                value[strcspn(value, "\n")] = '\0'; // \n entfernen
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                saveStackToFile(filename); // Beim Beenden speichern
                break;
            default:
                printf("Ungültige Wahl.\n");
        }

    } while (choice != 4);

    return 0;
}