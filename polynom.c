#include <stdio.h>
#include <math.h>
#include <stdlib.h> 

int main() {
    int degree;
    double *coefficients, x, result = 0.0;

    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);

    coefficients = (double *)malloc((degree + 1) * sizeof(double));
    if (coefficients == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter the coefficients (from highest degree to lowest):\n");
    for (int i = 0; i <= degree; i++) {
        printf("Coefficient for x^%d: ", degree - i);
        scanf("%lf", &coefficients[i]);
    }

    printf("Enter the value of x: ");
    scanf("%lf", &x);

    for (int i = 0; i <= degree; i++) {
        result += coefficients[i] * pow(x, degree - i);
    }

    printf("The result of the polynomial evaluation is: %.2f\n", result);

    free(coefficients);
    return 0;
}
// This program evaluates a polynomial of a given degree at a specified value of x.
// It dynamically allocates memory for the coefficients, reads them from user input,
// and computes the polynomial's value using Horner's method. The result is printed to two decimal places.
// The program also includes error handling for memory allocation failure.
// The coefficients are read in descending order of degree, and the result is calculated using a loop that iterates through each coefficient.
// The program uses the standard C library functions for input/output and memory management.