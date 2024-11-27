#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a term in the polynomial
typedef struct Term {
    int coeff; // Coefficient
    int exp;   // Exponent
} Term;

// Function to multiply two polynomials
void multiplyPolynomials(Term poly1[], int n1, Term poly2[], int n2, Term result[], int *resSize) {
    int i, j, k = 0;

    // Initialize result polynomial terms
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            int coeff = poly1[i].coeff * poly2[j].coeff;
            int exp = poly1[i].exp + poly2[j].exp;

            // Check if the term with this exponent already exists
            int found = 0;
            for (int l = 0; l < k; l++) {
                if (result[l].exp == exp) {
                    result[l].coeff += coeff;
                    found = 1;
                    break;
                }
            }

            // If not found, add a new term
            if (!found) {
                result[k].coeff = coeff;
                result[k].exp = exp;
                k++;
            }
        }
    }
    *resSize = k;
}

// Function to display a polynomial
void displayPolynomial(Term poly[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d*x^%d", poly[i].coeff, poly[i].exp);
        if (i < n - 1)
            printf(" + ");
    }
    printf("\n");
}

int main() {
    int n1, n2, resSize;
    Term poly1[50], poly2[50], result[100];

    // Input first polynomial
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);
    printf("Enter the terms of the first polynomial (coefficient and exponent):\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d %d", &poly1[i].coeff, &poly1[i].exp);
    }

    // Input second polynomial
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);
    printf("Enter the terms of the second polynomial (coefficient and exponent):\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d %d", &poly2[i].coeff, &poly2[i].exp);
    }

    // Multiply polynomials
    multiplyPolynomials(poly1, n1, poly2, n2, result, &resSize);

    // Display the result
    printf("Resulting polynomial after multiplication:\n");
    displayPolynomial(result, resSize);

    return 0;
}
