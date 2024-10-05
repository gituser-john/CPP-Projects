#include <stdio.h>

struct poly {
    int coef;
    int pow;       
};

void polydef(struct poly a[], int n) {
    for (int i = 0; i <= n; ++i) {
        a[i].pow = i;
        printf("Enter coefficient of x^%d : ", i);
        scanf("%d", &a[i].coef);
    }
}

void polyadd(struct poly a[], struct poly b[], struct poly c[], int m, int n, int max) {
    // Initialize result polynomial coefficients to zero
    for (int i = 0; i <= max; ++i) {
        c[i].coef = 0;
        c[i].pow = i;
    }

    for (int i = 0; i <= m; ++i) {
        c[i].coef += a[i].coef;
    }
    
    for (int i = 0; i <= n; ++i) {
        c[i].coef += b[i].coef;
    }
}

void printpoly(struct poly a[], int n) {
    int first = 1; // To handle the leading "+" sign
    for (int i = 0; i <= n; ++i) {
        if (a[i].coef != 0) {
            if (!first && a[i].coef > 0) {
                printf(" + ");
            }
            if (a[i].coef < 0) {
                printf(" - ");
            }
            if (a[i].coef < 0) {
                printf("%d", -a[i].coef);
            } else {
                printf("%d", a[i].coef);
            }
            if (a[i].pow != 0) {
                printf("x^%d", a[i].pow);
            }
            first = 0;
        }
    }
    if (first) {
        printf("0"); // Case where polynomial is zero
    }
    printf("\n");
}

int main() {
    int m, n, max;
    printf("Enter degrees of polynomial 1 and 2 : ");
    scanf("%d %d", &m, &n);
    max = (m > n) ? m : n;

    struct poly a[m + 1], b[n + 1], c[max + 1];

    printf("Enter first polynomial\n");
    polydef(a, m);
    printf("Enter second polynomial\n");
    polydef(b, n);

    polyadd(a, b, c, m, n, max);
    printf("Resultant polynomial:\n");
    printpoly(c, max);

    return 0;
}
