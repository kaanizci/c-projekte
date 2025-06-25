#include <stdio.h>

int main() {
    int amount;
    
    printf("Enter a dollar amount: ");
    scanf("%d", &amount);   // read the amount from user input

    int twenties = amount / 20;  // calculate number of $20 bills
    int tens = (amount % 20) / 10;  // calculate number of $10 bills
    int fives = (amount % 20 % 10) / 5;  // calculate number of $5 bills
    int ones = amount % 20 % 10 % 5;  // calculate number of $1 bills
    printf("Number of $20 bills: %d\n", twenties);
    printf("Number of $10 bills: %d\n", tens);
    printf("Number of $5 bills: %d\n", fives);
    printf("Number of $1 bills: %d\n", ones);
    printf("Total number of bills: %d\n", twenties + tens + fives + ones);
    printf("Total amount: $%d\n", amount);
    return 0;
}       