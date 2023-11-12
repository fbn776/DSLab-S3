#include <stdio.h>

typedef struct {
	int arr[10][10], m, n;
} Matrix;

typedef struct {
	int t_cols, t_rows, t_elms;
	int arr[100][3];
} SpareMatrix;

/**Prints a line to the stdout
 * @param len The length of the line
 * @param lineChar The character to be used for the lines
 * @param endsChar The character to be used at both ends (start and end)
 * @param borderSpace The space between each border. A special character is placed there
 * @param borderChar The character to be inserted at the borders
 */
void printLine(int len, char lineChar, char endsChar, int borderSpace, char borderChar) {
	int i;
	printf("%c", endsChar);
	for (i = 0; i < len; i++)
		printf("%c", ((i + 1) % borderSpace == 0) ? borderChar : lineChar);
	printf("%c\n", endsChar);
}

void readMatrix(Matrix *A) {
	int i, j;
	printf("Enter order (m n): ");
	scanf(" %d %d", &(A->m), &(A->n));
	printf("Enter elements:\n");
	for (i = 0; i < A->m; i++)
		for (j = 0; j < A->n; j++)
			scanf(" %d", &(A->arr[i][j]));
}

SpareMatrix convertToSparse(Matrix A) {
	int c = 0, i, j;
	SpareMatrix sm;

	sm.t_rows = A.m;
	sm.t_cols = A.n;

	for (i = 0; i < A.m; i++)
		for (j = 0; j < A.n; j++) {
			if (A.arr[i][j] != 0) {
				sm.arr[c][0] = i;
				sm.arr[c][1] = j;
				sm.arr[c++][2] = A.arr[i][j];
			}
		}
	sm.t_elms = c;
	return sm;
}

void displaySparse(SpareMatrix sm) {
	int i;

	printLine(29, '-', '*', 10, '-');
	printf("|%8s |%8s |%8s |\n", "Rows", "Cols", "Value");
	printLine(29, '=', '|', 10, '|');
	printf("|%8d |%8d |%8d |\n", sm.t_rows, sm.t_cols, sm.t_elms);
	printLine(29, '-', '|', 10, '|');
	for (i = 0; i < sm.t_elms; i++) {
		printf("|%8d |%8d |%8d |\n", sm.arr[i][0], sm.arr[i][1], sm.arr[i][2]);
		i == sm.t_elms - 1 ?: printLine(29, '-', '|', 10, '|');
	}
	printLine(29, '-', '*', 10, '-');
}

SpareMatrix add(SpareMatrix A, SpareMatrix B) {
	int i = 0, j = 0, k = 0;
	SpareMatrix C;
	if (A.t_rows != B.t_rows || A.t_cols != B.t_cols) {
		printf("Cannot multiply; invalid order\n");
		return C;
	}

	while (i <= A.t_elms && j <= B.t_elms) {
		if (A.arr[i][0] == B.arr[j][0] && A.arr[i][1] == B.arr[j][1]) {
			int result = A.arr[i++][2] + B.arr[j++][2];
			if(result == 0) {
				i++;
				j++;
				continue;
			}

			C.arr[k][0] = A.arr[i][0];
			C.arr[k][1] = A.arr[i][1];
			C.arr[k++][2] = result;
		}
		if ((A.arr[i][0] == B.arr[j][0] && A.arr[i][1] < B.arr[j][1]) || (A.arr[i][0] < B.arr[j][0])) {
			C.arr[k][0] = A.arr[i][0];
			C.arr[k][1] = A.arr[i][1];
			C.arr[k++][2] = A.arr[i++][2];
		}
		if ((A.arr[i][0] == B.arr[j][0] && A.arr[i][1] > B.arr[j][1]) || (A.arr[i][0] > B.arr[j][0])) {
			C.arr[k][0] = B.arr[j][0];
			C.arr[k][1] = B.arr[j][1];
			C.arr[k++][2] = B.arr[j++][2];
		}
	}

	while (i <= A.t_elms) {
		C.arr[k][0] = A.arr[i][0];
		C.arr[k][1] = A.arr[i][1];
		C.arr[k++][2] = A.arr[i++][2];
	}

	while (j <= B.t_elms) {
		C.arr[k][0] = B.arr[j][0];
		C.arr[k][1] = B.arr[j][1];
		C.arr[k++][2] = B.arr[j++][2];
	}

	C.t_rows = A.t_rows;
	C.t_cols = A.t_cols;
	C.t_elms = k;

	return C;
}

int main() {
	Matrix A, B;
	SpareMatrix As, Bs, Cs;

	readMatrix(&A);
	readMatrix(&B);

	As = convertToSparse(A);
	Bs = convertToSparse(B);

	printf("Sparse matrix of A:\n");
	displaySparse(As);
	printf("Sparse matrix of B:\n");
	displaySparse(Bs);

	Cs = add(As, Bs);
	printf("Sparse matrix of A + B:\n");
	displaySparse(Cs);
}