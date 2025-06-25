#include <stdio.h>

int main() {
    int itemnumber, mm, dd, yyyy;
    float unitprice;

    // Eingabe
    printf("Enter item number: ");
    scanf("%d", &itemnumber);

    printf("Enter unit price: ");
    scanf("%f", &unitprice);

    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &mm, &dd, &yyyy);

    // Ausgabe mit Tabs für Ausrichtung
    printf("\nItem\t\tUnit\t\tPurchase\n");
    printf("Number\t\tPrice\t\tDate\n");
    printf("%-8d\t$%7.2f\t\t%02d/%02d/%04d\n", itemnumber, unitprice, mm, dd, yyyy);

    return 0;
}