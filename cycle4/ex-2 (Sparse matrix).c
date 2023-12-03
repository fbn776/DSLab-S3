#include <stdio.h>

void readSparse(int R[][3]) {
	int m, n, A[10][10], i, j, t_elms = 0, k = 1;

	printf("Enter m n: ");
	scanf("%d %d", &m, &n);

	printf("Enter matrix:\n");
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			scanf(" %d", &A[i][j]);

	//Conversion to sparse;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++) {
			if(A[i][j] != 0) {
				R[k][0] = i;
				R[k][1] = j;
				R[k][2] = A[i][j];
				k++;
				t_elms++;
			}
		}

	R[0][0] = m;
	R[0][1] = n;
	R[0][2] = t_elms;
}

void transpose(int A[][3], int B[][3]) {
	int i, j, q = 1;
	for(i = 0; i < A[0][1]; i++)
		for(j = 1; j <= A[0][2]; j++) {
			if(A[j][1] == i) {
				B[q][0] = A[j][1];
				B[q][1] = A[j][0];
				B[q][2] = A[j][2];
				q++;
			}
		}

	B[0][0] = A[0][1];
	B[0][1] = A[0][0];
	B[0][2] = A[0][2];
}

void add(int A[][3], int B[][3], int C[][3]) {
	if(A[0][0] != B[0][0] || A[0][1] != B[0][1])
		return;

	int i = 1, j = 1, k = 1;
	while(i <= A[0][2] && j <= B[0][2]) {
		if(A[i][0] == B[j][0] && A[i][1] == B[j][1]) {
			C[k][0] = A[i][0];
			C[k][1] = A[i][1];
			C[k][2] = A[i][2] + B[j][2];
			k++; i++; j++;
		} else if((A[i][0] < B[j][0]) || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
			C[k][0] = A[i][0];
			C[k][1] = A[i][1];
			C[k][2] = A[i][2];
			k++; i++;
		} else {
			C[k][0] = B[j][0];
			C[k][1] = B[j][1];
			C[k][2] = B[j][2];
			k++; j++;
		}
	}

	while(i <= A[0][2]) {
		C[k][0] = A[i][0];
		C[k][1] = A[i][1];
		C[k][2] = A[i][2];
		k++; i++;
	}

	while(j <= B[0][2]) {
		C[k][0] = B[j][0];
		C[k][1] = B[j][1];
		C[k][2] = B[j][2];
		k++; j++;
	}

	C[0][0] = A[0][0];
	C[0][1] = A[0][1];
	C[0][2] = k - 1;
}

void display(int A[][3], char title[]) {
	printf("%s\n", title);
	int i;
	for(i = 0; i < A[0][2] + 1; i++)
		printf("%5d %5d %5d\n", A[i][0], A[i][1], A[i][2]);
}

int main() {
	int A[100][3], B[100][3], At[100][3], Bt[100][3], C[100][3];

	readSparse(A);
	readSparse(B);
	display(A, "Matrix A");
	display(B, "Matrix B");

	transpose(A, At);
	display(At, "A transpose");

	transpose(B, Bt);
	display(Bt, "B transpose");

	add(A, B, C);
	display(C, "Resultant");
}