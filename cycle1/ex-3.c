/**
 * Lowest number
 */

#include <stdio.h>

int main() {
	int ls[100], n, min, i;

	printf("Enter number of elements: ");
	scanf(" %d", &n);

	printf("Enter numbers: ");
	for(i=0; i<n; i++)
		scanf(" %d", &ls[i]);

	min = ls[0];

	for(i=0; i<n; i++) {
		if(ls[i] < min) {
			min = ls[i];
		}
	}

	printf("Smallest number is: %d\n", min);
}