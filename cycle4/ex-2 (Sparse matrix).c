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
	for(i = 0; i < len; i++)
		printf("%c", ((i + 1) % borderSpace == 0) ? borderChar : lineChar);
	printf("%c\n", endsChar);
}

void readMatrix(Matrix *A) {
	int i, j;
	printf("Enter order (m n): ");
	scanf(" %d %d", &(A->m), &(A->n));
	printf("Enter elements:\n");
	for(i = 0; i < A->m; i++)
		for(j = 0; j < A->n; j++)
			scanf(" %d", &(A->arr[i][j]));
}

SpareMatrix convertToSpare(Matrix A) {
	int c = 0, i, j;
	SpareMatrix sm;

	sm.t_rows = A.m;
	sm.t_cols = A.n;

	for(i = 0; i < A.m; i++)
		for(j = 0; j < A.n; j++) {
			if(A.arr[i][j] != 0) {
				sm.arr[c][0] = i;
				sm.arr[c][1] = j;
				sm.arr[c++][2] = A.arr[i][j];
			}
		}
	sm.t_elms = c;
	return sm;
}

void displaySpare(SpareMatrix sm) {
	int i;

	printLine(29, '-', '*', 10, '-');
	printf("|%8s |%8s |%8s |\n", "Rows", "Cols", "Value");
	printLine(29, '=', '|', 10, '|');
	printf("|%8d |%8d |%8d |\n", sm.t_rows, sm.t_cols, sm.t_elms);
	printLine(29, '-', '|', 10, '|');
	for(i = 0; i < sm.t_elms; i++) {
		printf("|%8d |%8d |%8d |\n", sm.arr[i][0], sm.arr[i][1], sm.arr[i][2]);
		i == sm.t_elms - 1 ? :printLine(29, '-', '|', 10, '|');
	}
	printLine(29, '-', '*', 10, '-');
}


int main() {
	Matrix A, B;

	readMatrix(&A);
//	readMatrix(&B);

	displaySpare(convertToSpare(A));
}