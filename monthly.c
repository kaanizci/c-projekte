#include <stdio.h>

int main() {
    double loan, interest_rate, monthly_payment;
    double monthly_interest;

    printf("Enter amount of loan: ");
    scanf("%lf", &loan);

    printf("Enter interest rate (annual in %%): ");
    scanf("%lf", &interest_rate);

    printf("Enter monthly payment: ");
    scanf("%lf", &monthly_payment);

    monthly_interest = interest_rate / 100.0 / 12.0;

    // 1. Monat
    loan = loan - monthly_payment + loan * monthly_interest;
    printf("Balance remaining after first payment: $%.2f\n", loan);

    // 2. Monat
    loan = loan - monthly_payment + loan * monthly_interest;
    printf("Balance remaining after second payment: $%.2f\n", loan);

    // 3. Monat
    loan = loan - monthly_payment + loan * monthly_interest;
    printf("Balance remaining after third payment: $%.2f\n", loan);

    return 0;
}