#include <stdio.h>

typedef struct {
	int coefficient;
} Term;

typedef struct {
	Term terms[100];
	int order;
} Polynomial;

Polynomial readPoly() {
	Polynomial ply;
	int i;

	printf("Enter order: ");
	scanf(" %d", &(ply.order));

	for (i = 0; i <= ply.order; i++) {
		printf("Enter term (x^%d): ", i);
		scanf(" %d", &(ply.terms[i].coefficient));
	}
	return ply;
}

Polynomial add(Polynomial p, Polynomial q) {
	int i, minOrder = p.order < q.order ? p.order : q.order, maxPly = 0;
	Polynomial r;
	Polynomial *plys[] = {&p, &q};
	//Order of r = max order (p, q)
	r.order = p.order > q.order ? (maxPly = 0, p.order) : (maxPly = 1, q.order);

	for (i = 0; i <= minOrder; i++) {
		r.terms[i].coefficient = p.terms[i].coefficient + q.terms[i].coefficient;
	}

	for (; i <= r.order; i++) {
		r.terms[i].coefficient = plys[maxPly]->terms[i].coefficient;
	}

	return r;
}

void display(Polynomial ply) {
	int i;
	Term curr;
	for (i = ply.order; i >= 0; i--) {
		curr = ply.terms[i];
		if (i != 0) {
			printf("%dx^%d", curr.coefficient, i);
			printf(" + ");
		} else {
			printf("%d", curr.coefficient);
		}
	}
	printf("\n");
}


int main() {
	Polynomial p, q, r;

	p = readPoly();
	q = readPoly();
	r = add(p, q);

	printf("Polynomial 1: ");
	display(p);
	printf("Polynomial 2: ");
	display(q);
	printf("Result: ");
	display(r);
}