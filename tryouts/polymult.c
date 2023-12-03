#include <stdio.h>

typedef struct {
	float coeff;
	int exp;
} Term;


void readPoly(Term A[], int *n) {
	printf("Enter order: ");
	scanf(" %d", n);

	int i;
	printf("Enter coefficients: \n");
	for (i = *n; i >= 0; i--) {
		printf("x^%d: ", i);
		scanf(" %f", &A[i].coeff);
		A[i].exp = i;
	}
}

void display(Term A[], int n) {
	int i;
	for (i = n; i >= 0; i--) {
		if (i == 0) {
			printf("%.2fx^%d\n", A[i].coeff, A[i].exp);
		} else {
			printf("%.2fx^%d + ", A[i].coeff, A[i].exp);
		}
	}
}

void add(Term A[], int a, Term B[], int b, Term C[], int *c) {
	int i = 0, j = 0, k = 0;
	while (i <= a && j <= b) {
		if (A[i].exp == B[j].exp) {
			C[k].coeff = A[i].coeff + B[j].coeff;
			C[k].exp = A[i].exp;
			i++;
			j++;
			k++;
		} else if (A[i].exp < B[i].exp) {
			C[k].coeff = A[i].coeff;
			C[k].exp = A[i].exp;
			k++;
			i++;
		} else {
			C[k].coeff = B[j].coeff;
			C[k].exp = B[j].exp;
			k++;
			j++;
		}
	}

	while(i <= a) {
		C[k].coeff = A[i].coeff;
		C[k].exp = A[i].exp;
		k++;
		i++;
	}

	while(j <= b) {
		C[k].coeff = B[j].coeff;
		C[k].exp = B[j].exp;
		k++;
		j++;
	}

	*c = a > b ? a : b;
}

int main() {
	Term A[10], B[10], C[10];
	int a, b, c;

	readPoly(A, &a);
	display(A, a);
	readPoly(B, &b);
	display(B, b);

	add(A, a, B, b, C, &c);
	display(C, c);
}