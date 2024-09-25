#include <stdio.h>
#include <math.h>

typedef struct {
    double coefficient;
    int exp_x;
    int exp_y;
} PolynomialTerm;

double evaluatePolynomial(PolynomialTerm terms[], int numTerms, double x, double y) {
    double result = 0.0;
    
    for (int i = 0; i < numTerms; i++) {
        PolynomialTerm term = terms[i];
        double termValue = term.coefficient * pow(x, term.exp_x) * pow(y, term.exp_y);
        result += termValue;
    }
    
    return result;
}

int main() {
    int numTerms;
    
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &numTerms);
    
    PolynomialTerm terms[numTerms];
    
    for (int i = 0; i < numTerms; i++) {
        printf("Enter the coefficient, exponent of x, and exponent of y for term %d:\n", i + 1);
        printf("Coefficient: ");
        scanf("%lf", &terms[i].coefficient);
        printf("Exponent of x: ");
        scanf("%d", &terms[i].exp_x);
        printf("Exponent of y: ");
        scanf("%d", &terms[i].exp_y);
    }
    
    double x, y;
    printf("Enter the value for x: ");
    scanf("%lf", &x);
    printf("Enter the value for y: ");
    scanf("%lf", &y);
    
    double result = evaluatePolynomial(terms, numTerms, x, y);
    
    printf("The result of the polynomial evaluation is: %lf\n", result);
    
    return 0;
}

