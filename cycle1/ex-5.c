/**
 * Binary search using pointers
 */

#include <stdio.h>

void bubbleSort(int *start, int *end) {
	int *ptr1, *ptr2;
	int temp;
	int swapped;

	for (ptr1 = start; ptr1 < end; ptr1++) {
		swapped = 0;
		for (ptr2 = start; ptr2 < end - 1; ptr2++) {
			if (*ptr2 > *(ptr2 + 1)) {
				temp = *ptr2;
				*ptr2 = *(ptr2 + 1);
				*(ptr2 + 1) = temp;
				swapped = 1;
			}
		}
		if (swapped == 0) {
			break;
		}
	}
}

int main() {
	int arr[100], n, i;


	printf("Enter number of elements: ");
	scanf("%d", &n);

	printf("Enter numbers: ");
	for (i = 0; i < n; i++) {
		scanf(" %d", &arr[i]);
	}

	bubbleSort(arr, arr + n);

	printf("\nSorted array: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}