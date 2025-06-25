#include <stdio.h>

int main() {
float amount, tax;

printf("Enter the amount in dollars and cents: ");
scanf("%f", &amount);  // read the amount from user input

tax = amount * 0.05f;  // calculate 5% tax on the amount

printf("The total amount including tax is: $%.2f\n", amount + tax);

return 0;
}